#include <stdio.h>

/*
 * Problema 1021 URI
 */

/*
 * No problema em questão, a entrada teve q ser dividida em parte
 * inteira e parte fracionada pois estava ocorrendo um problema de
 * arredondamento e estava sumindo com 1 centavo.
 */

int main() {
	int coins[12];
	int notas[12] = {100, 50, 20, 10, 5, 2, 1, 50, 25, 10, 5, 1};
	int a, b;
	scanf("%d.%d", &a, &b);
	int i;
	for(i = 0; i < 7; i++) {
		coins[i] = a/notas[i];
		a -= notas[i]*coins[i];
		
	}
	for(i = 7; i < 12; i++) {
		coins[i] = b/notas[i];
		b -= notas[i]*coins[i];
	}
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n",coins[0]);
	printf("%d nota(s) de R$ 50.00\n" ,coins[1]);
	printf("%d nota(s) de R$ 20.00\n" ,coins[2]);
	printf("%d nota(s) de R$ 10.00\n" ,coins[3]);
	printf("%d nota(s) de R$ 5.00\n"  ,coins[4]);
	printf("%d nota(s) de R$ 2.00\n"  ,coins[5]);
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n" ,coins[6]);
	printf("%d moeda(s) de R$ 0.50\n" ,coins[7]);
	printf("%d moeda(s) de R$ 0.25\n" ,coins[8]);
	printf("%d moeda(s) de R$ 0.10\n" ,coins[9]);
	printf("%d moeda(s) de R$ 0.05\n" ,coins[10]);
	printf("%d moeda(s) de R$ 0.01\n" ,coins[11]);

	return 0;
}