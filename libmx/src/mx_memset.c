#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t a) {
    unsigned char *p = (unsigned char *)b;

    for (size_t i = 0; i < a; i++)
        p[i] = (unsigned char)c;
    return b;
}
