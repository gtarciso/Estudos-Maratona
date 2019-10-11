#include <stdio.h>

int main() {
	int cod, quant, i;
	double valor, soma = 0.0;
	for(i = 0; i < 2; i++) {
		scanf("%d", &cod);
		scanf("%d", &quant);
		scanf("%lf", &valor);
		soma += quant*valor; 
	}
	printf("VALOR A PAGAR: R$ %.2lf\n", soma);
	return 0;
}