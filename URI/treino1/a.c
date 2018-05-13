#include <stdio.h>

/*
 * Problema 1020 URI
 */

int main() {
	int n;
	scanf("%d", &n);
	int y, m, d;
	y  = n/365;
	n  = n - 365*y;
	m  = n/30;
	n  = n - 30*m;
	d  = n;
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", y, m, d);
	return 0;
}