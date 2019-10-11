#include <stdio.h>
#include <algorithm>

/*
 * Problema 1104 URI
 */

#define MAX 10000

using namespace std;

int search(int n, int v[MAX], int tam) {
	int inf = 0;
	int sup = tam-1;
	int meio;
	while(inf <= sup) {
		meio = (inf+sup)/2;
		if(n == v[meio]) {
			return 0;
		}
		if(n < v[meio]) {
			sup = meio-1;
		} else {
			inf = meio+1;
		}
	}
	return 1;
}


int main() {
	while(1) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		if(a == 0 && b == 0) break;
		int al[MAX];
		int be[MAX];
		int i;
		for(i = 0; i < a; i++) {
			scanf("%d", &al[i]);
		}
		for(i = 0; i < b; i++) {
			scanf("%d", &be[i]);
		}
		int anteriora = 0, anteriorb = 0;
		int contA = 0, contB = 0;
		for(i = 0; i < a; i++) {
			if(al[i] != anteriora) {
				contA += search(al[i], be, a);
			}
			anteriora = al[i];
		}
		for(i = 0; i < b; i++) {
			if(be[i] != anteriorb) {
				contB += search(be[i], al, b);
			}
			anteriorb = be[i];
		}
		if(contA < contB) {
			printf("%d\n", contA);
		} else {
			printf("%d\n", contB);
		}
	}
	return 0;
}