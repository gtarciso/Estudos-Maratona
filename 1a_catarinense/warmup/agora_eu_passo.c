#include <stdio.h>

int main() {
	int c = 1;
	int i, j = 0;
	float pesos, p = 0.0, notaFinal, pesoProvao, nota;
	scanf("%d", &c);
	while(c) {
		pesos = 0.0;
		notaFinal = 0.0;
		for (i = 0; i < c-1; i++) {
			scanf("%f", &nota);
			scanf("%f", &p);
			notaFinal += nota*p;
			pesos += p;
		}
		pesoProvao = 1.0 - pesos;
		scanf("%f", &nota);
		notaFinal += pesoProvao * nota;
		if(notaFinal >= 5.0) {
			printf("aprovado\n");
		} else {
			printf("volte no exame\n");
		}
		scanf("%d", &c);
	}
	return 0;
}