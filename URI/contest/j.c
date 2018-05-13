#include <stdio.h>

/*
 * Problema 2392 URI
 */

int main() {
	int n;
	int s, i;
	scanf("%d", &n);
	scanf("%d", &s);
	int v[101];
	for(i = 0; i <= 100; i++) {
		v[i] = 0;
	}
	for(i = 0; i < s; i++) {
		int p, salto, j;
		scanf("%d", &p);
		scanf("%d", &salto);
		for(j = p; j <= n; j+= salto)
			v[j] = 1;
		for(j = p; j >= 0; j-= salto)
			v[j] = 1;
	}
	for(i = 1; i <= n; i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}