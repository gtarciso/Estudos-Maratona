#include <stdio.h>

/*
 * Problem 2340 - URI
 */

int main() {
	int n;
	scanf("%d", &n);
	int max = 0, x, i;
	for(i = 0; i < n; i++) {
		int g, d;
		scanf("%d %d", &g, &d);
		int aux = (g-1)*d;
		if(aux > max) {
			max = aux;
			x = i;
		}
	}
	printf("%d\n", x);
	return 0;
}