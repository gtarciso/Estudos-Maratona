#include <stdio.h>

int main() {
	int km;
	double l;
	scanf("%d", &km);
	scanf("%lf", &l);
	printf("%.3lf km/l\n", km/l);
	return 0;
}