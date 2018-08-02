#include <stdio.h>
#include <string.h>

/*
 * Maior subsequencia crescente
 */

int max(int i, int j) {
    if(i > j) {
        return i;
    } else {
        return j;
    }
}

int ssc_max(int A[], int n) {
	int c[n];
	for(int i = 0; i < n; i++) {
	    c[i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(A[j] < A[i]) {
			    c[i] = max(c[i], c[j]+1);
			}
		}
	}
	int max = 0;
	for(int i = 0; i < n; i++) {
	    if(max < c[i]) {
	        max = c[i];
	    }
	}
	return max;
}

int main() {

	int n, t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		int A[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &A[j]);
		}
		printf("%d\n", ssc_max(A, n));
	}

	return 0;

}