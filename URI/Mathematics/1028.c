#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int n, i;
	scanf("%d", &n);
	int *results = malloc(sizeof(int)*n);
	for(i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		results[i] = gcd(a,b);
	}
	for(i = 0; i < n; i++) {
		printf("%d\n", results[i]);
	}
	return 0;
}
