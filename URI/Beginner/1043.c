#include <stdio.h>

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	int flag = 0;

	if(a+b <= c) flag = 1;
	if(a+c <= b) flag = 1;
	if(b+c <= a) flag = 1;

	if(flag == 0) {
		printf("Perimetro = %.1lf\n", a+b+c);
	} else {
		printf("Area = %.1lf\n", ((a+b)*c)/2);
	}
	return 0;
}