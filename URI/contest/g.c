#include <stdio.h>

/*
 * Problema 2318 URI
 */

struct tuplas {
	int line;
	int col;
};

int main() {
	int quad[3][3];
	int i, j, cont = 0;
	struct tuplas t[3];
	for(i = 0; i < 3; i++) {
		t[i].line = 0;
		t[i].col = 0;
	}
	for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
			scanf("%d", &quad[i][j]);
			if(quad[i][j] == 0) {
				t[cont].line = i;
				t[cont].col = j;
				cont++;
			}
		}
	}
	int p[8];
	for(i = 0; i < 8; i++) {
		p[i] = 0;
	}
	for(i = 0; i < 3; i++) {
		p[0] += quad[0][i];
		p[1] += quad[1][i];
		p[2] += quad[2][i];
		p[3] += quad[i][0];
		p[4] += quad[i][1];
		p[5] += quad[i][2];
		p[6] += quad[i][i];
	}
	p[7] = quad[2][0] + quad[0][2] + quad[1][1];
	int flag = 0;
	int max = 0;
	for(i = 0; i < 8; i++) {
		if(p[i] > max)
			max = p[i];
	}
	int maior = 0;
	if(p[6]==0){
		quad[1][1] = p[1]/2;
		max = quad[1][1]+p[1];
		quad[0][0] = max - p[0];
		quad[2][2] = max - p[2];
	} else if(p[7] == 0) {
		quad[1][1] = p[1]/2;
		max = quad[1][1] + p[1];
		quad[0][2] = max - p[0];
		quad[2][0] = max - p[2];
	} else {
		for(i = 0; i < 3; i++) {
			if(p[i] == 0) {
				quad[i][0] = max - p[3];
				quad[i][1] = max - p[4];
				quad[i][2] = max - p[5];
				flag = 1;
			} else if(p[i+3] == 0) {
				quad[0][i] = max - p[0];
				quad[1][i] = max - p[1];
				quad[2][i] = max - p[2];
				flag = 1;
			}
		}
		if(flag == 0) {
			for(i = 0; i < cont; i++) {
				int sub1 = 0;
				int sub2 = 0;
				int nzero = 0;
				for(j = 0; j < 3; j++) {
					sub1 += quad[t[i].line][j];
					if(quad[t[i].line][j] == 0)
						nzero++;
					sub2 += quad[j][t[i].col];
					if(quad[j][t[i].col] == 0)
						nzero++;
				}


				int best = 0;

				if(sub1 >= best && sub1 != max)
					best = sub1;
				if(sub2 >= best && sub2 != max)
					best = sub2;
				
				if(nzero >= 4) {
					cont++;
					t[cont-1].line = t[i].line;
					t[cont-1].col = t[i].col;
					continue;
				}


				quad[t[i].line][t[i].col] = max - best;
			}
		}
	}
	for(i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d", quad[i][j]);
			if(j != 2)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}