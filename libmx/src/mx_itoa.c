#include "../inc/libmx.h"

static int number_length(int n) {
	int l = 0;

	while (n) {
		n /= 10;
		l++;
	}
	return l;
}

char *mx_itoa(int n) {
	int l = number_length(n);
	int tmp = n;
	char *r = NULL;

	r = mx_strnew(l);
	if (n == 0)
		return mx_strcpy(r, "0");
	if (n == -2147483648)
		return mx_strcpy(r, "-2147483648");
	tmp = n;
	for (int i = 0; i < l; i++) {
		if (tmp < 0) {
			r[l] = '-';
			tmp = -tmp;
		}
		r[i] = (tmp % 10) + '0';
		tmp /= 10;
	}
	mx_str_reverse(r);
	return r;
}
