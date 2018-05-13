#include <stdio.h>

/*
 * Problema 1128 URI
 */

#define MAX 2000

int adjacencia[MAX][MAX];

int transposto[MAX][MAX];

int visited[2000];

int stack[2000];

int print[2000];

int prtcount;

int flag;

int stack_counter;

void dfs(int v, int n);

void transpose(int n);

void fill(int v, int n);

void kosaraju(int n, int v) {
	int i;
	for(i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(i = 1; i <= n; i++) {
		if(visited[i] == 0)
			fill(i, n);
	}
	transpose(n);
	for(i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	while(stack_counter >= 0) {
		int vx;
		vx = stack[stack_counter-1];
		stack_counter--;
		if(visited[vx] == 0)
			dfs(vx, n);
		if(prtcount < n){
			flag = 1;
			return;
		}
	}

}

void fill(int v, int n) {
	visited[v] = 1;
	int i;
	for(i = 1; i <= n; i++) {
		if(visited[i] == 0 && adjacencia[v][i] == 1 && i != 0)
			fill(i, n);
	}
	stack[stack_counter] = v;
	stack_counter++;
}

void dfs(int v, int n) {
	visited[v] = 1;
	print[prtcount] = v;
	prtcount++;
	int i;
	for(i = 1; i <= n; i++) {
		if(transposto[v][i] == 1 && visited[i] == 0 && i != 0)

			dfs(i, n);
	}
}

void transpose(int n) {
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(adjacencia[i][j] == 1) {
				transposto[j][i] = 1;
			}
		}
	}
}

int main() {
	int n=1;
	while(n != 0) {
		stack_counter = 0;
		prtcount = 0;
		flag = 0;
		int ruas, i, j;
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d", &ruas);
		for(i = 1; i <= ruas; i++) {
			int v, w, p;
			scanf("%d", &v);
			scanf("%d", &w);
			scanf("%d", &p);
			adjacencia[v][w] = 1;
			if(p == 2)
				adjacencia[w][v] = 1;
		}
		int nv = 0;
		kosaraju(n, 3);
		
		for(i = 1; i <= n; i++) {
			nv += visited[i];
		}

		if(nv == n) {
			printf("1\n");
		} else {
			printf("0\n");
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				transposto[i][j] = 0;
				adjacencia[i][j] = 0;
			}
		}
	}
	return 0;
}