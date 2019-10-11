#include <stdio.h>

/*
 * Problema 1089 URI
 */

#define MAX 10000

int main() {
	int n = 1;
	while(n != 0) {
		int v[MAX+2];
		int i, cont = 0;
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		for(i = 1; i < n+1; i++) {
			scanf("%d", &v[i]);
		}
		if(n == 2) {
			if (v[1] != v[2]) {
				cont = 2;
			}
		} else {
			v[n+1] = v[1];
			v[0] = v[n];
			for(i = 1; i < n+1; i++) {
				if(v[i] > v[i-1] && v[i] > v[i+1]) {
					cont++;
				}
				if(v[i] < v[i-1] && v[i] < v[i+1]) {
					cont++;
				}
			}
		}
		printf("%d\n", cont);
	}
	return 0;


}