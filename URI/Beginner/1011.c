#include <stdio.h>

#define pi 3.14159

int main() {
	double radius;
	scanf("%lf", &radius);
	printf("VOLUME = %.3lf\n", radius*radius*radius*pi*(4.0/3.0));
	return 0;
}