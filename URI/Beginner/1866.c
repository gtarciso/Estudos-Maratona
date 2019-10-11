#include <stdio.h>

int main() {
	int n;
	int x, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		printf("%d\n", x%2);
	}
	return 0;
}