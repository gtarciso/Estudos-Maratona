#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i;
	int aux;
	for(i = 0; i < n; i++) {
		scanf("%d", &aux);
		if(aux == 0) {
			printf("NULL\n");
			continue;
		}
		if(aux%2 == 0) {
			if(aux > 0) {
				printf("EVEN POSITIVE\n");
			} else {
				printf("EVEN NEGATIVE\n");
			}
		} else {
			if(aux > 0) {
				printf("ODD POSITIVE\n");
			} else {
				printf("ODD NEGATIVE\n");
			}
		}
	}
	return 0;
}