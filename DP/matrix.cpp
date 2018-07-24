#include <stdio.h>
#include <limits.h>

using namespace std;

int dp[101][101];

int min(int a, int b) {
	if(a < b) return a;
	return b;
}

int matrix(int m[], int n) {
	
	for(int i = 0; i <= n; i++) {
		dp[i][i] = 0;	
	}

	for(int s = 1; s < n; s++) {
		for(int i = 1; i <= n-s; i++) {
			int j = i + s;
			dp[i][j] = INT_MAX;
			for(int k = i; k <= j-1; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
			}
		}
	}
	return dp[1][n];
}

int main() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int quant;
		scanf("%d", &quant);
		int m[quant+1];
		for(int j = 0; j < quant; j++) {
			scanf("%d", &m[j]);
		}
		printf("%d\n", matrix(m, quant-1));
	}
	return 0;

}