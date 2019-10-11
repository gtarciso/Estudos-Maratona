#include <stdio.h>

#define MAX 100

/*
 * Problema 2371 URI
 */

int visited[MAX][MAX];

int total;

int seek(int l, int c, int n, int m, char table[MAX][MAX]) {
	visited[l][c] = 1;
	if(l-1 >= 0 && visited[l-1][c] == 0) {
		visited[l-1][c] = 1;
		if(table[l-1][c] == 'a') {
			if(seek(l-1, c, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l-1][c] == '#') {
			visited[l][c] = 0;
			visited[l-1][c] = 0;
			return 0;
		}
	}
	if(l+1 < n && visited[l+1][c] == 0) {
		visited[l+1][c] = 1;
		if(table[l+1][c] == 'a') {
			if(seek(l+1, c, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l+1][c] == '#') {
			visited[l][c] = 0;
			visited[l+1][c] = 0;
			return 0;
		}
	}
	if(c-1 >= 0 && visited[l][c-1] == 0) {
		visited[l][c-1] = 1;
		if(table[l][c-1] == 'a') {
			if(seek(l, c-1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l][c-1] == '#') {
			visited[l][c] = 0;
			visited[l][c-1] = 0;
			return 0;
		}
	}
	if(c+1 < m && visited[l][c+1] == 0) {
		visited[l][c+1] = 1;
		if(table[l][c+1] == 'a') {
			if(seek(l, c+1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l][c+1] == '#') {
			visited[l][c] = 0;
			visited[l][c+1] = 0;
			return 0;
		}
	}
	// diagonal
	if(c-1 >= 0 && l-1 >= 0 && visited[l-1][c-1] == 0) {
		visited[l-1][c-1] = 1;
		if(table[l-1][c-1] == 'a') {
			if(seek(l-1, c-1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l-1][c-1] == '#') {
			visited[l][c] = 0;
			visited[l-1][c-1] = 0;
			return 0;
		}
	}
	if(c-1 >=0 && l+1 < n && visited[l+1][c-1] == 0) {
		visited[l+1][c-1] = 1;
		if(table[l+1][c-1] == 'a') {
			if(seek(l+1, c-1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l+1][c-1] == '#') {
			visited[l][c] = 0;
			visited[l+1][c-1] = 0;
			return 0;
		}
	}
	if(c+1 < m && l-1 >= 0 && visited[l-1][c+1] == 0) {
		visited[l-1][c+1] = 1;
		if(table[l-1][c+1] == 'a') {
			if(seek(l-1, c+1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l-1][c+1] == '#') {
			visited[l][c] = 0;
			visited[l-1][c+1] = 0;
			return 0;
		}
	}
	if(c+1 < m && l+1 < n && visited[l+1][c+1] == 0) {
		visited[l+1][c+1] = 1;
		if(table[l+1][c+1] == 'a') {
			if(seek(l+1, c+1, n, m, table) == 0) {
				return 0;
			}
		} else if(table[l+1][c+1] == '#') {
			visited[l][c] = 0;
			visited[l+1][c+1] = 0;
			return 0;
		}
	}
	return 1;
}

int main() {
	int n, m;
	while(1) {
		char table[MAX][MAX];
		char aux;
		total = 0;
		scanf("%d", &n);
		if(n==0) break;
		scanf("%d", &m);
		int i, j;
		for(i = 0; i < MAX; i++) {
			for(j = 0; j < MAX; j++) {
				visited[i][j] = 0;
			}
		}
		for(i = 0; i < n; i++) {
			do {
				scanf("%c", &aux);
			} while(aux != '\n');
			for(j = 0; j < m; j++) {
				scanf("%c", &table[i][j]);
			}		
		}
		int k;
		scanf("%d", &k);
		for(i = 0; i < k; i++) {
			int l, c;
			scanf("%d", &l);
			scanf("%d", &c);
			if(table[l-1][c-1] == '#')
				table[l-1][c-1] = 'a';
		}
		int c = 0, var = 0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(visited[i][j] == 0) {
					if(table[i][j] == 'a') {
						c += seek(i, j, n, m, table);
						if(c > var) {
							var++;
						}
					}
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}