#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int max(int a, int b) {
	if(a > b) return a;
	return b;
}


int palindrome(char w[]) {
	int n = strlen(w);
	int dp[n][n];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}


	for(int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for(int i = 0; i < n-1; i++) {
		if(w[i] == w[i+1]) {
			dp[i][i+1] = 2;
		} else {
			dp[i][i+1] = 1;
		}
	} 

	for(int s = 1; s < n ; s++) {
		for(int i = 0; i < n-s; i++) {
			int j = i+s;

			if(w[i] == w[j]) {
				dp[i][j] = dp[i+1][j-1]+2;
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}

	return dp[0][n-1];

}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		char str[1002];
		cin >> str;
		printf("%d\n", palindrome(str));
	}
	return 0;
}