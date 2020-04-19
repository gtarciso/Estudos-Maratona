#include <stdio.h>

int main() {
	int counter = 0;
	int i;
	double x;
	for(i = 0; i < 6; i++) {
		scanf("%lf", &x);
		if(x > 0) {
			counter++;
		}
	}
	printf("%d valores positivos\n", counter);
	return 0;
}