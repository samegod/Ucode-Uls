#include "uls.h"

void mx_out_err(t_li ***er, st_fl *fl) {
    if (er && *er && **er) {
        mx_sort(er, fl);
        fl->files = 1;
        fl->ex = 1;
        for (int i = 0; (*er)[i]; i++) {
            mx_printerr("uls: ");
            mx_printerr((*er)[i]->name);
            mx_printerr(": ");
            mx_printerr((*er)[i]->err);
            mx_printerr("\n");
            mx_strdel(&(*er)[i]->name);
            mx_strdel(&(*er)[i]->path);
            mx_strdel(&(*er)[i]->err);
            free((*er)[i]);
            (*er)[i] = NULL;
        }
        free(*er);
        *er = NULL;
    }
}

void mx_printcharerr(char c) {
    write(2,&c,1);
}
