#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int w[102];
int wdp[102][102];
int dp[102][102];

void peso(int n) {
	for(int i = 1; i <= n; i++) {
		wdp[i][i] = w[i];
	}

	for(int s = 1; s < n; s++) {
		for(int i = 1; i <= n-s; i++) {
			int j = s+i;
			wdp[i][j] = wdp[i][j-1]+w[j];
		}
	}
}

int obst(int n) {

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	
	for(int s = 1; s < n; s++) {
		for(int i = 1; i <= n-s; i++) {
			int j = s+i;
			dp[i][j] = INT_MAX;
			for(int k = i; k <= j; k++) {
				if(k == n) {
					dp[i][j] = min(dp[i][k-1]+wdp[i][j]-w[k], dp[i][j]);
					continue;
				}
				dp[i][j] = min(dp[i][k-1]+dp[k+1][j]+wdp[i][j]-w[k], dp[i][j]);				
			}
		}
	}

	return dp[1][n-1];

}

int main() {
	int teste = 1;
	while("True") {
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		peso(n);
		printf("Teste %d\n", teste);
		printf("%d\n\n", obst(n+1));
		teste++;
	}
	return 0;
}
