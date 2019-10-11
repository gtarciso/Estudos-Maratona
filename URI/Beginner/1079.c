#include <stdio.h>

int main() {
	double p1, p2, p3;
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%lf", &p1);
		scanf("%lf", &p2);
		scanf("%lf", &p3);
		printf("%.1lf\n", (p1*0.2+p2*0.3+p3*0.5));
	}
	return 0;
}