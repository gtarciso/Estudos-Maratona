#include <stdio.h>

#define SALTO 10
#define MAX 100000

int main() {
	int quant, flag, i, j, k, cont;
	int array[MAX];
	scanf("%d", &quant);
	while(quant > 0) {
		cont = 0;
		flag = 0;
		for(i = 0; i < quant; i++) {
			scanf("%d", &array[i]);
		}
		i = 0;//ranubia
		j = 1;//ranoberto
		k = 2;
		while(k < quant) {
			if((array[k] - array[i]) > SALTO || (array[k+1] - array[j]) > SALTO) {
				flag = 1;
				break;
			}
			while(k < quant && (array[k] - array[i]) <= SALTO) {
				k++;
			}
			if(k == quant || k == j+1) {
				cont++; 
				break;
			}
			k--;
			while(k < quant && (array[k+1] - array[j]) >= SALTO) {
				k--;
			}
			i = j;
			j = k;
			k++;
			cont++;
		}
		if(flag == 1) {
			printf("-1\n");
		} else {
			printf("%d\n", cont);
		}
		scanf("%d", &quant);
	}
	return 0;
}