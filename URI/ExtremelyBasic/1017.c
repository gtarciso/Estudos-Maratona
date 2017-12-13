#include <stdio.h>

int main() {
	int hours, kmh;
	scanf("%d", &hours);
	scanf("%d", &kmh);
	double kml = (hours*kmh)/12.0;
	printf("%.3lf\n", kml);
	return 0;
}