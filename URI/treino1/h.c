#include <stdio.h>

/*
 * Problema 1323 URI
 */

int main() {
	while(1) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		int i;
		int total = 0;
		for(i = 1; i <= n; i++) {
			total += i*i;
		}
		printf("%d\n", total);
	}
	return 0;
}