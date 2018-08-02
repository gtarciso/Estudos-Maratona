#include <stdio.h>

/*
 * Problema 2300 URI
 */

#define MAX 101

int visited[MAX];

void dfs(int v, int n, int graph[][MAX]) {
	visited[v] = 1;
	int i;
	for(i = 0; i < n; i++) {
		if(graph[v][i] == 1 && visited[i] == 0) {
			dfs(i, n, graph);
		}
	}
}

int main() {
	int teste = 1;
	while(1) {
		int e, l;
		int i, j;
		int graph[MAX][MAX];
		for(i = 0; i < MAX; i++) {
			visited[i] = 0;
			for(j = 0; j < MAX; j++) {
				graph[i][j] = 0;
			}
		}
		scanf("%d", &e);
		scanf("%d", &l);
		if(e == 0 && l == 0) break;
		for(i = 0; i < l; i++) {
			int m, n;
			scanf("%d", &m);
			scanf("%d", &n);
			graph[m-1][n-1] = 1;
			graph[n-1][m-1] = 1;
		}
		if(l < e-1) {
			printf("Teste %d\nfalha\n\n", teste);
			continue;
		}
		dfs(0, e, graph);
		int total = 0;
		for(i = 0; i < e; i++) {
			total += visited[i];
		}
		if(total == e) {
			printf("Teste %d\nnormal\n\n", teste);
		} else {
			printf("Teste %d\nfalha\n\n", teste);
		}
		teste++;


	}
	return 0;
}