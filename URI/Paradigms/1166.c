#include <stdio.h>

int main() {
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		int balls = 0;
		int n, j;
		scanf("%d", &n);
		for(j = 1; j <= n; j++) {
			balls += j;
		}
		int soma;
		if(n % 2 == 0) {
			soma = n/2 -1;
		} else {
			soma = n/2;
		}
		printf("%d\n", balls+soma);
	}
	return 0;
}