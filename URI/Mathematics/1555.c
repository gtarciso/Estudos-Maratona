#include <stdio.h>

/*
 * Problema 1555 URI
 */

int main() {
	int n;
	scanf("%d", &n);
	int i;
	long long int a, b, c, x, y;
	for(i = 0; i < n; i++) {
		scanf("%lld", &x);
		scanf("%lld", &y);
		
		a = ((3*x)*(3*x))+y*y;
		b = (2*x*x)+((5*y)*(5*y));
		c = (-1*100*x)+(y*y*y);

		if(a > b && a > c) {
			printf("Rafael ganhou\n");
		} else if(b > a && b > c) {
			printf("Beto ganhou\n");
		} else {
			printf("Carlos ganhou\n");
		}
	}
	return 0;
}