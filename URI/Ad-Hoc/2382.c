#include <stdio.h>
#include <math.h>

/*
 * Problema 2382 URI
 */

int main() {
	int r;
	int a, l, p;
	scanf("%d", &a);
	scanf("%d", &l);
	scanf("%d", &p);
	scanf("%d", &r);

	r = r*2;

	double hip1 = sqrt(l*l + a*a);
	double hip2 = sqrt(p*p + a*a);

	if(hip1 > (double)r || hip2 > (double)r) {
		printf("N\n");
	} else {
		printf("S\n");
	}
	return 0;
}