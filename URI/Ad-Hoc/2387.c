#include <stdio.h>

#define MAX 10000

/*
 * Problema 2387 URI
 */

struct Horarios {
	int entrada;
	int saida;
	int tempo;
};

int main() {
	int n = 1;
	scanf("%d", &n);
	struct Horarios h[MAX];
	if(n == 0) break;

	int count = 0, in, out, i, j;
	for(i = 0; i < n; i++) {
		scanf("%d", &in);
		scanf("%d", &out);
		h[i].entrada = in;
		h[i].saida = out;
		h[i].tempo = out-in;
	}

	for(i = 0; i < n; i++) {
		for(j = i; j < n; j++) {
			if(h[i].saida > h[j].saida) {
				struct Horarios aux = h[j];
				h[j] = h[i];
				h[i] = aux;
			}
		}
	}
	out = 0;
	for(i = 0; i < n; i++) {
		if(h[i].entrada >= out) {
			count++;
			out = h[i].saida;
		}
	}

	printf("%d\n", count);
	return 0;
}