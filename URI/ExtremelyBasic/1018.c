#include <stdio.h>

int notas[7] = {100, 50, 20, 10, 5, 2, 1};

int main() {
	int n;
	scanf("%d", &n);
	int v[7];
	int i;
	printf("%d\n", n);
	for(i = 0; i < 7; i++) {
		v[i] = n/notas[i];
		n -= v[i]*notas[i];
		printf("%d nota(s) de R$ %d,00\n", v[i], notas[i]);
	}
	return 0;

}