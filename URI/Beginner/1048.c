#include <stdio.h>

int main() {
	double value, nvalue;
	int percent;
	scanf("%lf", &value);
	if(value <= 400.0) {
		percent = 15;
		nvalue = value*1.15;
	} else if(value > 400.00 && value <= 800.0 ) {
		percent = 12;
		nvalue = value*1.12;
	} else if(value > 800 && value <= 1200.0) {
		percent = 10;
		nvalue = value*1.10;
	} else if(value > 1200 && value <= 2000.0) {
		percent = 7;
		nvalue = value*1.07;
	} else {
		percent = 4;
		nvalue = value*1.04;
	}

	printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", nvalue, nvalue-value, percent);

	return 0;
}