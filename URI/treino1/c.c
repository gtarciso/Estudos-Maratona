#include <stdio.h>

/*
 * Problema 1071 URI
 */

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	int i, j;
	if(a >= b) {
		i = a;
		j = b;
	} else {
		i = b;
		j = a;
	}
	j++;
	int sum = 0;
	for(; j < i; j++) {
		if(j%2 == 1 || (-j)%2 == 1) {
			sum += j;
		}
	}
	printf("%d\n", sum);
	return 0;
}