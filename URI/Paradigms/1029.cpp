#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cont;
int calls;

int fib(int n) {
	calls++;
	if(n < 2) {
		cont +=n;
		return n;
	} else {
		return fib(n-2)+fib(n-1);
	}

}

int main() {
	int n, i;
	cin >> n;
	int *ca = (int*)malloc(sizeof(int)*n);
	int *co = (int*)malloc(sizeof(int)*n);
	int *va = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++) {
		cont = 0;
		calls = 0;
		cin >> va[i];
		fib(va[i]);
		co[i] = cont;
		ca[i] = calls-1;

	}
	for(i = 0; i < n; i++) {
		printf("fib(%d) = %d calls = %d\n", va[i], ca[i], co[i]);
	}
	return 0;
}

