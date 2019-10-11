#include <stdio.h>

/*
 * Problem 2125 - URI
 */

 struct find {
 	int col;
 	int lin;
 };

 int check(int i, int j, int m, char totem[1000][1000], char sig[60][60]) {
 	int l, k;

 	for(l = 0; l < m; l++) {
 		for(k = 0; k < m; k++) {
 			if(sig[l][k] != totem[l+i][j+k]) return 0;
 		}
 	}
 	return 1;	
 }


 int main() {
 	int k = 1;
 	int m, n;
 	while(scanf("%d %d", &n, &m) != EOF) {
	 	char totem[1000][1000];
	 	char sig[60][60];
	 	struct find a[1000];
	 	int c = 0;
	 	;
	 	int i, j;
	 	char x;
	 	scanf("%c", &x);
	 	for(i = 0; i < n; i++) {
	 		for(j = 0; j < n; j++) {
	 			scanf("%c", &totem[i][j]);
	 		}
	 		char aux;
	 		scanf("%c", &aux);
	 	}
	 	for(i = 0; i < m; i++) {
	 		for(j = 0; j < m; j++) {
	 			scanf("%c", &sig[i][j]);
	 		}
	 		char aux;
	 		scanf("%c", &aux);
	 	}
	 	
	 	for(i = 0; i <= (n-m); i++) {
	 		for(j = 0; j <= (n-m); j++) {
	 			if(check(i, j, m, totem, sig) == 1) {
	 				struct find aux;
	 				aux.col = j;
	 				aux.lin = i;
	 				a[c] = aux;
	 				c++;
	 			}
	 		}
	 	}
	 	for(i = 0; i < c; i++) {
	 		for(j = i; j < c; j++) {
	 			if(a[i].col > a[j].col) {
	 				struct find aux = a[j];
	 				a[j] = a[i];
	 				a[i] = aux;
	 			}
	 		}
	 	}
	 	for(i = 0; i < c; i++) {
	 		for(j = i; j < c; j++) {
	 			if(a[i].col == a[j].col) {
	 				if(a[i].lin > a[j].lin) {
	 					struct find aux = a[j];
	 					a[j] = a[i];
	 					a[i] = aux;
	 				}
	 			}
	 		}
	 	}
	 	printf("Instancia %d\n", k);
	 	if(c == 0) {
	 		printf("no occurrence\n");
	 	} else {
	 		for(i = 0; i < c; i++) {
	 			printf("%d %d\n", a[i].lin, a[i].col);
	 		}
	 	}
	 	k++;
	}
	return 0;

 }