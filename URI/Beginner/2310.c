#include <stdio.h>

/*
 * Problema 2310 URI
 */

int main() {
	int n;
	scanf("%d", &n);
	int i;
	int servt = 0, blockt = 0, atckt = 0, srv = 0, blk = 0, atk = 0;
	for(i = 0; i < n; i++) {
		char a[50];
		int aux;
		scanf("%s", a);
		scanf("%d", &aux);
		servt += aux;
		scanf("%d", &aux);
		blockt += aux;
		scanf("%d", &aux);
		atckt += aux;

		scanf("%d", &aux);
		srv += aux;
		scanf("%d", &aux);
		blk += aux;
		scanf("%d", &aux);
		atk += aux;

	}
	printf("Pontos de Saque: %.2lf %%.\n", ((double)srv/(double)servt)*100);
	printf("Pontos de Bloqueio: %.2lf %%.\n", ((double)blk/(double)blockt)*100);
	printf("Pontos de Ataque: %.2lf %%.\n", ((double)atk/(double)atckt)*100);
	return 0;
}