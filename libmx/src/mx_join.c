#include "../inc/libmx.h"

void mx_join(char **r, char *s2) {
    char *s = mx_strnew(mx_strlen(*r) + mx_strlen(s2));
    int i = 0;
    int si = -1;
    char *s1 = *r;

    while(s1[++si]) {
        s[i] = s1[si];
        i++;
    }
    si = -1;
    while(s2[++si]) {
        s[i] = s2[si];
        i++;
    }
    mx_strdel(&(*r));
    *r = s;
}
