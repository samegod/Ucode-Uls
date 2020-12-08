#include "uls.h"
static char mx_check_per(t_li *pr) {
    if (IS_DIR(pr->info.st_mode))
        return 'd';
    if (IS_LNK(pr->info.st_mode))
        return 'l';
    if (IS_BLK(pr->info.st_mode))
        return 'b';
    if (IS_CHR(pr->info.st_mode))
        return 'c';
    if (IS_FIFO(pr->info.st_mode))
        return 'p';
    if (IS_SOCK(pr->info.st_mode))
        return 's';
    if (IS_WHT(pr->info.st_mode))
        return 'w';
    return '-';
}
static char mx_get_file_acl(t_li *print) {
    acl_t tmp;

    if (listxattr(print->path, NULL, 0, XATTR_NOFOLLOW) > 0)
        return ('@');
    if ((tmp = acl_get_file(print->path, ACL_TYPE_EXTENDED))) {
        acl_free(tmp);
        return ('+');
    }
    return (' ');
}
static char check_chmode2(char *chm) {
    if (chm[9] == '-')
        return chm[9] = 'T';
    else
        return chm[9] = 't';
}
static char check_chmode1(char chm) {
    if (chm == '-')
        return chm = 'S';
    else
        return chm = 's';
}
void mx_print_per(t_li *pr) {
    char chmod[12];
    chmod[0] = mx_check_per(pr);
    chmod[1] = (S_IRUSR & pr->info.st_mode) ? 'r' : '-';
    chmod[2] = (S_IWUSR & pr->info.st_mode) ? 'w' : '-';
    chmod[3] = (S_IXUSR & pr->info.st_mode) ? 'x' : '-';
    chmod[4] = (S_IRGRP & pr->info.st_mode) ? 'r' : '-';
    chmod[5] = (S_IWGRP & pr->info.st_mode) ? 'w' : '-';
    chmod[6] = (S_IXGRP & pr->info.st_mode) ? 'x' : '-';
    chmod[7] = (S_IROTH & pr->info.st_mode) ? 'r' : '-';
    chmod[8] = (S_IWOTH & pr->info.st_mode) ? 'w' : '-';
    chmod[9] = (S_IXOTH & pr->info.st_mode) ? 'x' : '-';
    chmod[10] = mx_get_file_acl(pr);
    chmod[11] = '\0';
    S_ISUID & pr->info.st_mode ? chmod[3] = check_chmode1(chmod[3]) : 0;
    S_ISGID & pr->info.st_mode ? chmod[6] = check_chmode1(chmod[6]) : 0;
    S_ISVTX & pr->info.st_mode ? chmod[9] = check_chmode2(chmod) : 0;
    for (int i = 0; chmod[i]; i++)
        mx_printchar(chmod[i]);
    mx_printchar(' ');
}
