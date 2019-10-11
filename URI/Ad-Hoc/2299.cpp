#include <stdio.h>
#include <stdlib.h>


/*
 * Problema 2299 URI
 */

int max(int a, int b) {
	if(a > b) return a;
	return b;
}

int knapsack(int W, int wt[], int val[], int n) {
	int i, w;
	int K[n+1][W+1];
	for(i = 0; i <= n; i++) {
		for(w = 0; w <= W; w++) {
			if(i == 0 || w == 0) {
				K[i][w] = 0;
			} else if(wt[i-1] <= w) {
				K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]);
			} else {
				K[i][w] = K[i-1][w];
			}
		}
	}
	return K[n][W];
}

int main() {
	int test = 1;
	while(1) {
		int W, n;
		scanf("%d", &W);
		scanf("%d", &n);
		if(W == 0 && n == 0) break;

		int val[51];
		int wt[51];
		int i;
		for(i = 0; i < n; i++) {
			scanf("%d", &wt[i]);
			scanf("%d", &val[i]);
		}
		int value = knapsack(W, wt, val, n);
		printf("Teste %d\n%d\n\n", test, value);
		test++;
	}
	return 0;
}