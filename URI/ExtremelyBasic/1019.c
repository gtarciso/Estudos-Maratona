#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int h, m, s;
	h = n/3600;
	n -= h*3600;
	m = n/60;
	n -= m*60;
	s = n;
	printf("%d:%d:%d\n", h, m, s);
	return 0;
}