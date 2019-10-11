#include <stdio.h>
#include <math.h>

/*
 * Problema 1295 URI - não aceito (time limit exceeded)
 */

#define MAX 10000

struct POINT {
	int x;
	int y;
};

int main() {
	while(1) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;

		struct POINT values[MAX];
		int i, j; 
		double minor = MAX;
		for(i = 0; i < n; i++) {
			scanf("%d", &values[i].x);
			scanf("%d", &values[i].y);
		}
		for(i = 0; i < n; i++) {
			for(j = i; j < n; j++) {
				int delta = (values[i].x - values[j].x) * (values[i].x - values[j].x);
				delta += (values[i].y - values[j].y) * (values[i].y - values[j].y);
				double aux = sqrt(delta);
				//printf("%lf\n", aux);
				if(aux < minor && aux != 0) {
					minor = aux;
				}
			}
		}
		if(minor == MAX) {
			printf("INFINITY\n");
		} else {
			printf("%.4lf\n", minor);
		}
	}
	return 0;
}