#include <stdio.h>

/*
 * Problema 1105 URI
 */

#define MAX 21

int main() {
	long int banks[MAX];
	while(1) {
		int n, b;
		scanf("%d", &b);
		scanf("%d", &n);
		if(b == 0 && n == 0) break;
		int i;
		for(i = 0; i < MAX; i++) {
			banks[i] = 0;
		}
		for(i = 0; i < b; i++) {
			scanf("%ld", &banks[i]);
		}
		for(i = 0; i < n; i++) {
			int k, m, p;
			scanf("%d", &k);
			scanf("%d", &m);
			scanf("%d", &p);
			banks[k-1] = banks[k-1] - p;
			banks[m-1] = banks[m-1] + p;
		}
		int tag = 0;
		for(i = 0; i < b; i++) {
			if(banks[i] < 0) {
				tag = 1;
				break;
			}
		}
		if(tag == 0) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}