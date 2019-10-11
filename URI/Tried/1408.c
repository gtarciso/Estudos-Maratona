#include <stdio.h>
#include <string.h>

/*
 * Problem 1408 URI
 */

 int main() {

 	while(1) {
 		int n, l;
 		scanf("%d %d", &n, &l);
 		if(n == 0 && l == 0) break; 		
 		int max = 0, cont = 1;
 		int i;
 		long int pos, limit, anterior;
 		scanf("%ld", &anterior);
 		for(i = 1; i < l; i++) {
 			scanf("%ld", &pos);
 			if(pos == anterior+1) {
 				cont++;
 			} else {
 				if(cont > max) {
 					max = cont;
 				}
 				cont = 1;
 			}
 			anterior = pos;
 		}
 		
 		printf("%d\n", n - max);
 	}
 	return 0;

 }