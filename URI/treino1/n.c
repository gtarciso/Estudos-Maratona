#include <stdio.h>

/*
 * Problema 2375 URI
 */

int main() {
	int diametro;
	scanf("%d", &diametro);
	int a, l, p;
	scanf("%d", &a);
	scanf("%d", &l);
	scanf("%d", &p);

	if(a < diametro || l < diametro || p < diametro) {
		printf("N\n");
	} else {
		printf("S\n");
	}
	return 0;
}