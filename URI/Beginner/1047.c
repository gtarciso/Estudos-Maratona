#include <stdio.h>

int main() {
	int h1, m1, h2, m2;

	scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

	int hora = 0, minuto = 0;

	if(h1 <= h2) {
		hora = (h2-h1);
	} else {
		hora = 24-h1+h2;	
	}

	if(m1 < m2) {
		minuto = m2 - m1;
	} else {
		minuto = 60-m1+m2;
		hora--;
	}
	if(m1 == m2) {
		minuto = 0;
		hora++;
	}

	if(hora < 0) {
		hora += 24;
	}


	if(h1 == h2 && m1 == m2) {
		hora = 24;
		minuto = 0;
	}

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hora, minuto);

	return 0;

}