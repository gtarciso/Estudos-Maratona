#include <stdio.h>
#include <stdlib.h>

int calls;
int *p;
int *result;

int fib(int n) {
	calls++;
	if(p[n] == 1)
		return result[n];
	else {
		p[n] = 1;
		if(n < 2) {
			result[n] = n;
			return n;
		}
		else {
			result[n] = fib(n-1)+fib(n-2);
			return result[n];
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	int *r = malloc(sizeof(int)*n);
	int *x = malloc(sizeof(int)*n);
	int *c = malloc(sizeof(int)*n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		calls = 0;
		p = malloc(sizeof(int)*x[i]);
		result = malloc(sizeof(int)*x[i]);
		r[i] = fib(x[i]);
		c[i] = calls;
		r[i] = result[i];
	}
	for(i = 0; i < n; i++) 	
		printf("fib(%d) = %d calls = %d\n", x[i], c[i], r[i]);
	return 0;
}
