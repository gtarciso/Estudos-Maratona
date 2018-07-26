#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;


struct itens {
	int peso;
	int valor;
};

struct itens it[101];

bool compare2itens(struct itens a, struct itens b) {
	return ((double)a.valor/(double)a.peso > (double)b.valor/(double)b.peso);
}

int main() {

	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		int n, w;
		scanf("%d %d", &n, &w);
		for(int j = 0; j < n; j++) {
			scanf("%d %d", &it[j].valor, &it[j].peso);
		}

		sort(it, it+n, compare2itens);
		
		double total = 0.0;
		int k = 0;
		while(w > 0 && k < n) {
			int quant;
			if(it[k].peso > w) {
				quant = w;
			} else {
				quant = it[k].peso;
			}

			total += (double)it[k].valor/double(it[k].peso)*quant;


			w -= quant;
			k++;
		}

		printf("%.2lf\n", total);

	}

	return 0;

}