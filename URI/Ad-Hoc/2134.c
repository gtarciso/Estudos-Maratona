#include <stdio.h>
#include <string.h>

/*
 * Problem 2134 URI
 */

 int main() {
 	int n;
 	int instancia = 1;
 	while(scanf("%d", &n) != EOF) {
 		int i, min = 11, nota;
 		char name[25];
 		char aux[25];
 		int l;
 		for(i = 0; i < n; i++) {
 			scanf("%s %d", aux, &nota);

 			if(min >= nota) {
 				if(min == nota) {
 					if((strcmp(name, aux)) < 0) {
 						min = nota;
 						strcpy(name, aux);
 					}
 				} else {
 					min = nota;
 					strcpy(name, aux);
 				}
 			}
 		}
 		printf("Instancia %d\n%s\n\n", instancia, name);

 		instancia++;
 	}
 	return 0;
 }