#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct caixa {
	int y; // altura
	int x; // largura
	int z; // comprimento
};

int max(int x, int y) {
	if (x < y) return y;
	return x;
}

bool compare2caixas(struct caixa a, struct caixa b) {
	return ((a.x*a.z)>(b.x*b.z));
}

int alturaCaixas(struct caixa a[], int n) {
	sort(a, a+n, compare2caixas);

	int dp[n];
	for(int i = 0; i < n; i++) {
		dp[i] = a[i].y;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[j].x > a[i].x && a[j].z > a[i].z) {
				dp[i] = max(dp[i], dp[j]+a[i].y);
			}
		}
	}
	int maior = 0;
	for(int i = 0; i < n; i++) {
		if (maior < dp[i]) maior = dp[i];
	}
	return maior;
}

int main() {
	int n;
	while(1) {
		scanf("%d", &n);
		struct caixa caixas[n*6];
		if(n == 0) break;
		for(int i = 0; i < n*6; i+= 6) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			caixas[i  ].x = x;
			caixas[i  ].y = y;
			caixas[i  ].z = z;

			caixas[i+1].x = y;
			caixas[i+1].y = z;
			caixas[i+1].z = x;
			
			caixas[i+2].x = z;
			caixas[i+2].y = x;
			caixas[i+2].z = y;

			caixas[i+3].x = x;
			caixas[i+3].y = z;
			caixas[i+3].z = y;

			caixas[i+4].x = y;
			caixas[i+4].y = x;
			caixas[i+4].z = z;

			caixas[i+5].x = z;
			caixas[i+5].y = y;
			caixas[i+5].z = x;

		}
		printf("%d\n", alturaCaixas(caixas, n*6));

	}
	return 0;
}