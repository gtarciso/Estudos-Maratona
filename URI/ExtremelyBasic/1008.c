#include <stdio.h>

int main() {
	int number, hours;
	double amnt;
	scanf("%d", &number);
	scanf("%d", &hours);
	scanf("%lf", &amnt);
	printf("NUMBER = %d\n", number);
	printf("SALARY = U$ %.2lf\n", amnt*hours);
	return 0;
}