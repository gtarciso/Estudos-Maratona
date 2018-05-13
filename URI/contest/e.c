#include <stdio.h>

/*
 * Problema 1467 URI
 */

int main() {
	int a, b, c;
	while(scanf("%d", &a) != EOF) {
		scanf("%d", &b);
		scanf("%d", &c);
		if(a != b && a != c) {
			printf("%s\n", "A");
		} else if(b != a && b != c) {
			printf("%s\n", "B");
		} else if(c != a && c != b) {
			printf("%s\n", "C");
		} else {
			printf("%s\n", "*");
		}
	}
	return 0;
}