#include <stdio.h>

int main() {
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	int result;
	if(n1 > n2) {
		result = n1 % n2;
	} else {
		result = n2 % n1;
	}

	if(result == 0) {
		printf("Sao Multiplos\n");
	} else {
		printf("Nao sao Multiplos\n");
	}
	return 0;
}