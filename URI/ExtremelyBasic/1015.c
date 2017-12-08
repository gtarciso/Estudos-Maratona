#include <stdio.h>
#include <math.h>

int main() {
	double x1, y1, x2, y2;
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	double x = x2-x1;
	double y = y2-y1;
	double delta = x*x + y*y;
	printf("%.4lf\n", sqrt(delta));
	return 0;
}