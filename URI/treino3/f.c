#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Problem 2129 - URI
 */

 /* reverse:  reverse string s in place */
 void reverse(char s[]) {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

  /* itoa:  convert n to characters in s */
 int itoa(int n, char s[]) {
     int i, sign;
     int lenght = 0;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';  /* get next digit */
         lenght++;  
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
     return lenght;
 }

 int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

 int factNonZero(int n) {

 	if(n < 10) {
 		return dig[n];
 	}

 	if(((n/10)%10)%2 == 0) {
 		return ((6*factNonZero(n/5)*dig[n%10])%10);
 	} else {
 		return ((4*factNonZero(n/5)*dig[n%10])%10);
 	}
 }

int main() {
	int n;
	int k = 1;
	while(scanf("%d", &n) != EOF) {
		char a[10];
		int l = itoa(n, a);
		char aux = a[l-2];
		int d = aux-'0';
		int x = factNonZero(n);
		printf("Instancia %d\n", k);
		printf("%d\n", x);
		printf("\n");
		k++;
	}
	return 0;
}