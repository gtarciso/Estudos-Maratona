#include <stdio.h>

/*
 * Problema 1091 URI
 */

int main() {
	while(1) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;

		int divX, divY;
		scanf("%d", &divX);
		scanf("%d", &divY);

		int i;
		for(i = 0; i < n; i++) {
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			if(x == divX || y == divY) {
				printf("divisa\n");
			} else if(x > divX && y > divY) {
				printf("NE\n");
			} else if(x < divX && y > divY) {
				printf("NO\n");
			} else if(x < divX && y < divY) {
				printf("SO\n");
			} else {
				printf("SE\n");
			}
		}
	}
	return 0;
}