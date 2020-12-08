#include "../inc/libmx.h"

void *mx_memmove(void *b, const void *c, size_t a) {
	unsigned char *tmp = malloc(a);

	tmp = mx_memcpy(tmp, c, a);
	b = mx_memcpy(b, tmp, a);
	free(tmp);
	return b;
}
