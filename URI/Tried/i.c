#include <stdio.h>

#define MAX 1000

void imprime(int mtx[][MAX], int m, int n) {
	int i, j;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			printf("%d", mtx[i][j]);
			if(j != n-1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void deslH(int a[][MAX], int x, int m, int n) {
	
	int i, j;
	int aux[MAX][MAX];
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			int k;
			k = (j+x) % n;
			if(k < 0) {
				k = (k+n) % n;
			}
			aux[i][k] = a[i][j];
		}
	}

	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = aux[i][j];
		}
	}
}

void deslV(int a[][MAX], int y, int m, int n) {
	int i, j;
	int aux[MAX][MAX];
	for(i = 0; i < m; i++) {
		int k;
		k = (i-y) % n;
		if(k < 0) {
			k = (k+m) % m;
		}
		for(j = 0; j < n; j++) {
			aux[k][j] = a[i][j];
		}
	}
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = aux[i][j];
		}
	}
}

int main() {
	int mtx[MAX][MAX];
	int teste = 1;
	while(1) {
		int m, n;
		scanf("%d", &m);
		scanf("%d", &n);
		if(m == 0 && n == 0) break;
		int i, j;
		for(i = 0; i < m; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &mtx[i][j]);
			}
		}
		int x, y;
		while(1) {
			scanf("%d", &x);
			scanf("%d", &y);
			if(x == 0 && y == 0) break;
			deslH(mtx, x, m, n);
			deslV(mtx, y, m, n);

		}
		printf("Teste %d\n", teste);
		imprime(mtx, m, n);
		teste++;

	}
	return 0;
}