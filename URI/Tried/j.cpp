#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <queue>

#define MAX 101

using namespace std;

int N[MAX];
int B[MAX];
double v;

inline void pivot(int x, int y, double A[MAX][MAX], double b[MAX], double c[MAX], int h, int s) {
	for(int i = 0; i < s; i++) {
		if(i != y) {
			A[x][i] /= -A[x][y];
		}
	}
	b[x] /= -A[x][y];
	A[x][y] = 1.0/A[x][y];

	for(int i = 0; i < h; i++) {
		if(i != x) {
			for(int j = 0; j < s; j++) {
				if(j != y) {
					A[i][j] += A[i][y] * A[x][j];
				}
			}
			b[i] += A[i][y]*b[x];
			A[i][y] *= A[x][y];
		}
	}

	for(int i = 0; i < s; i++) {
		if(i != y) {
			c[i] += c[y] * A[x][i];
		}
	}
	v += c[y] * b[x];
	c[y] *= A[x][y];

	swap(B[x], N[y]);
}

inline int iterate_simplex(double A[MAX][MAX], double b[MAX], double c[MAX], int h, int s) {
	int ind = -1, best_var = -1;
	for(int i = 0; i < s; i++) {
		if(c[i] > 0) {
			if(best_var == -1 || N[i] < ind) {
				ind = N[i];
				best_var = i;
			}
		}
	}
	if(ind == -1) return 1;

	double max_constr = INFINITY;

	int best_constr = -1;
	for(int i = 0; i < h; i++) {
		if(A[i][best_var] < 0) {
			double curr_constr = -b[i] / A[i][best_var];
			if(curr_constr < max_constr) {
				max_constr = curr_constr;
				best_constr = i;
			}
		}
	}

	if(isinf(max_constr)) return -1;
	else pivot(best_constr, best_var, A, b, c, h, s);

	return 0;
}

inline int initialize_simplex(double A[MAX][MAX], double b[MAX], double c[MAX], int h, int s) {
	int k = -1;
	double min_b = -1;
	for(int i = 0; i < h; i++) {
		if(k == -1 || b[i] < min_b) {
			k = i;
			min_b = b[i];
		}
	}

	if(b[k] >= 0) {
		for(int i = 0; i < s; i++) N[i] = i;
		for(int i = 0; i < h; i++) B[i] = s+i;
	}
	double c_old[MAX];
	for(int i = 0; i < s-1; i++) c_old[i] = c[i];
	
	double v_old = v;
	
	c[s-1] = -1;

	for(int i = 0; i < s-1; i++) c[i] = 0;
	v = 0;
	for(int i = 0; i < h; i++) A[i][s-1] = 1;

	pivot(k, s-1, A, b, c, h, s);

	int code;
	while(!(code = iterate_simplex(A, b, c, h, s)));

	assert(code == 1);

	if(v != 0) return -1;

	int z_basic = -1;
	for(int i = 0; i < h; i++) {
		if(b[i] == s-1) {
			z_basic = i;
			break;
		}
	}

	if(z_basic != -1) pivot(z_basic, s-1, A, b, c, h, s);

	int z_nonbasic = -1;
	for(int i = 0; i < s; i++) {
		if(N[i] == s-1) {
			z_nonbasic = i;
			break;
		}
	}

	assert(z_nonbasic != -1);

	for(int i = 0; i < h; i++) {
		A[i][z_nonbasic] = A[i][s-1];
	}
	swap(N[	z_nonbasic], N[s-1]);
	s--;

	for(int i = 0; i < s; i++) if (N[i] > s) N[i]--;
	for(int j = 0; j < h; j++) if (B[j] > s) B[j]--;

	for(int i = 0; i < s; i++) c[i] = 0;

	v = v_old;

	for(int i = 0; i < s; i++) {
		bool ok = false;
		for(int j = 0; j < s; j++) {
			if(i == N[j]) {
				c[j] += c_old[i];
				ok = true;
				break;
			}
		}
		if(ok) continue;
		for(int k = 0; k < h; k++) {
			if(i == B[k]) {
				for(int j = 0; j < s; j++) {
					c[j] = c_old[i] * A[k][j];
				}
				v += c_old[i] * b[k];
				break;
			}
		}
	}

	return 0;
}

pair<vector<double>, double> simplex(double A[MAX][MAX], double b[MAX], double c[MAX], int h, int s) {
	if(initialize_simplex(A, b, c, h, s) == -1) {
		return make_pair(vector<double>(s+h, -2), INFINITY);
	}

	int code;
	while(!(code = iterate_simplex(A, b, c, h, s)));

	if(code == -1) return make_pair(vector<double> (s+h, -1), INFINITY);

	vector<double> ret;
	ret.resize(s+h);
	for(int i = 0; i < s; i++) {
		ret[N[i]] = 0;
	}

	for(int i = 0; i < h; i++) {
		ret[B[i]] = b[i];
	}

	return make_pair(ret, v);
}


bool bfs(int x[MAX][MAX], int s, int t, int parent[], int n) {
	bool visited[MAX];
	memset(visited, 0, sizeof(visited));

	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int v = 0; v < n; v++) {
			if(visited[v] == false && x[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return (visited[t] == true); 
}

int fordFulkerson(int x[MAX][MAX], int s, int t, int n) {
	int u, v;
	int r[MAX][MAX];
	for(u = 0; u < n; u++) {
		for(v = 0; v < n; v++) {
			r[u][v] = x[u][v];
		}
	}
	int parent[MAX];
	int max_flow = 0;

	while(bfs(r, s, t, parent, n)) {
		int path_flow = INT_MAX;
		for(v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, r[u][v]);
		}

		for(v = t; v != s; v = parent[v]) {
			u = parent[v];
			r[u][v] -= path_flow;
			r[v][u] += path_flow;
		}

		max_flow += path_flow;
	}
	return max_flow;
}

int main() {
	int h;
	int instancia = 1;
	while(scanf("%d", &h) != EOF) {
		int s, a;
		scanf("%d", &s);
		scanf("%d", &a);
		double mtx[MAX][MAX];
		double mont[MAX];
		int ns[MAX];
		int i, j;
		for(i = 0; i < MAX; i++) {
			for(j = 0; j < MAX; j++) {
				mtx[i][j] = 0;
			}
		}
		for(i = 0; i < h; i++) {
			mont[i] = 0;
			//scanf("%d", &mont[i]);
		}
		for(i = 0; i < a; i++) {
			int m, k;
			scanf("%d", &m);
			scanf("%d", &k);
			//mtx[m-1][k-1] = mont[m-1];
			//mtx[k-1][m-1] = mont[m-1];
		}
		double c[MAX];
		for(i = 0; i < s; i++) {
			c[MAX] = 1;
		}
		int max;

		s = 2, h = 2;
		mtx[0][0] = -1;
		mtx[0][1] =  1;
		mtx[1][0] = -2;
		mtx[1][1] = -1;
		mont[0] = 1; mont[1] = 2;
		c[0] = 5; c[1] = -3;

		pair<vector<double>, double> ret = simplex(mtx, mont, c, h, s);
		for(int i = 0; i < s+h; i++) {
			printf("%lf\n", ret.second);
		}
		/*
		for(i = 0; i < h; i++) {
			//mtx[h-1][i] = 1;
			//mtx[i][h-1] = 1;
		}

		int max = fordFulkerson(mtx, 0, h-1, h);
		max += fordFulkerson(mtx, h-1, 0, h);
		*/
		printf("instancia %d\n%d\n", instancia, max);
		instancia++;
	}

	return 0;
}

