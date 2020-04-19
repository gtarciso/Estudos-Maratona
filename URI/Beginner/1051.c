#include <stdio.h>

int main() {
	double x;
	scanf("%lf", &x);
	double imposto = 0.0;
	if(x <= 2000.00) {
		printf("Isento\n");
		return 0;
	}
	if(x > 2000.00 && x <= 3000.00) {
		imposto += (x-2000.00)*0.08;
	}
	if(x > 3000.00 && x <= 4500.00) {
		imposto += ((x - 3000.00)*0.18) + 80;
	}
	if(x > 4500.00) {
		imposto += ((x - 4500.00)*0.28) + 350;
	}

	printf("R$ %.2lf\n", imposto);
	return 0;
}