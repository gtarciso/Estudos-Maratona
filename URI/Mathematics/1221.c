#include <stdio.h>
#include <math.h>

/*
 * Problema 1221 URI
 */

int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(x == 1) {
			printf("Not Prime\n");
			continue;
		}
		if(x == 2) {
			printf("Prime\n");
			continue;
		}
		if(x%2 == 0) {
			printf("Not Prime\n");
			continue;
		}
		int j, tag = 0;
		for(j = 3; j <= sqrt(x)+1; j+=2) {
			if(x % j == 0) {
				tag = 1;
				break;
			}
		}
		if(tag == 1) {
			printf("Not Prime\n");
		} else {
			printf("Prime\n");
		}
	}
	return 0;
}