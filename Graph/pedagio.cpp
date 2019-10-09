#include <stdio.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int g[51][51];

int mark[51];

int cost[51];

/*
 * Não faz parte do problema/solução, coloquei a busca em profundidade aqui
 * para não precisar criar outro arquivo para imprimir pro livro do time da maratona
 */

void dfs(int v, int c, int n, int cont) {
	mark[v] = 1;
	if(cont == n) return;
	for(int i = 0; i < c; i++) {
		if(g[v][i] == 1 && mark[i] == 0) {
			dfs(i, c, n, cont+1);
		}
	}
}

/*********************************************************************************/

queue<int> mq;

int solution[51];
int it;

bool compare(int a, int b) {
	return a < b;
}

int bfs(int root, int cities, int p) {
	mark[root];
	mq.push(root);
	cost[root] = 0;
	while(!mq.empty()) {
		int v = mq.front();
		mq.pop();
		for(int i = 0; i < cities; i++) {
			if(mark[i] == 0 && g[v][i] == 1) {
				mark[i] = 1;
				cost[i] = cost[v]+1;
				mq.push(i);
				if(cost[i] <= p) {
					solution[it] = i;
					it++;
				}
			}
		}
	}
}


int main() {
	int teste = 1;
	while(1) {
		int c, e, l, p; // c = cidades, e = estradas, l = lugar de inicio, p = pedagios
		scanf("%d %d %d %d", &c, &e, &l, &p);

		if(c == 0 && e == 0 && l == 0 && p == 0) break;
		it = 0;
		for(int i = 0; i < 51; i++) {
			mark[i] = 0;
			cost[i] = 0;
			solution[i] = 0;
			for(int j = 0; j < 51; j++) {
				g[i][j] = 0;
			}
		}
		int x, y;
		for(int i = 0; i < e; i++) {
			scanf("%d %d", &x, &y);
			g[x][y] = 1;
			g[y][x] = 1;
		}
		bfs(l, c, p);
		sort(solution, solution+it, compare);
		printf("Teste %d\n", teste);
		for(int i = 0; i < it; i++) {
			if(solution[i] != l)
				printf("%d ", solution[i]);
		}
		printf("\n\n");
		teste++;
	}

	return 0;
}