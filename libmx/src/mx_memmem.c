#include "../inc/libmx.h"

void *mx_memmem(const void *b, size_t bl, const void *l, size_t l_1) {
	unsigned char *where = NULL;
	unsigned char *what = NULL;

	if (bl >= l_1 && bl > 0 && l_1 > 0) {
		where = (unsigned char *)b;
		what = (unsigned char *)l;
		while (*where) {
			if (mx_memcmp(where, what, l_1 - 1) == 0)
				return where;
			where++;
		}
	}
	return NULL;
}
