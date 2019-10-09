#include <stdio.h>

int main() {
	double n1, n2, n3, n4;
	scanf("%lf", &n1);
	scanf("%lf", &n2);
	scanf("%lf", &n3);
	scanf("%lf", &n4);
	double media = (2*n1 + 3*n2 + 4*n3 + n4)/10;
	printf("Media: %.1lf\n", media);
	if(media >= 7.0) {
		printf("Aluno aprovado.\n");
		return 0;
	} else if (media >= 5.0) {
		printf("Aluno em exame.\n");
		double exame;
		scanf("%lf", &exame);
		printf("Nota do exame: %.1lf\n", exame);
		double media_f = (media + exame)/2;
		if(media_f >= 5.0) {
			printf("Aluno aprovado.\n");
		} else {
			printf("Aluno reprovado.\n");
		}
		printf("Media final: %.1lf\n", media_f);
	} else {
		printf("Aluno reprovado.\n");
	}
	return 0;
}