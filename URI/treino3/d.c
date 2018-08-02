#include <stdio.h>

/*
 * Problem 1486 - URI
 */

#define MAX 1000

int main() {
	int m[MAX][MAX];
	while(1) {
		int p, n, c;
		scanf("%d %d %d", &p, &n, &c);
		if(p == 0 && n == 0 && c == 0) break;
		int i, j;
		for(i = 0; i < n; i++) {
			for(j = 0; j < p; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		int value = 0;
		int cont;
		for(i = 0; i < p; i++) {
			for(j = 0; j < n; j++) {
				if(m[j][i] == 1) {
					cont++;
				} else {
					if(cont >= c) {
						value++;
					}
					cont = 0;
				}
			}
			if(cont >= c) value++;
			cont = 0;
		}
		printf("%d\n", value);
	}
	return 0;
}