#include <stdio.h>


int mdc(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return mdc(b, a % b);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	int i, j;
	int aux;
	int count = 0;
	for(i = 1; i <= n; i++) {
		aux = n%i;
		for(j = 1; j <= n; j++) {
			if(j <= aux) {
				count++;
			}
		} 
	}
	int n_2 = n*n;
	int _mdc = mdc(n_2, count);
	printf("%d/%d\n", count/_mdc, n_2/_mdc);
	return 0;
}