#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


bool flood(int path[25], int d[25], int matrix[5][5], int i, int j) {
	if(d[i*5+j] == 1) {
		return false;
	}
	d[i*5+j] = 1;
	if(matrix[i][j] == 1) {
		return false;
	}
	if(path[i*5+j] == 1) {
		if(j > 0 && matrix[i][j-1] == 0) {
			path[i*5+(j-1)] = 1;
			flood(path, d, matrix, i, j-1);
		}
		if(j < 4 && matrix[i][j+1] == 0) {
			path[i*5+(j+1)] = 1;
			flood(path, d, matrix, i, j+1);
		}
		if(i < 4 && matrix[i+1][j] == 0) {
			path[(i+1)*5+j] = 1;
			flood(path, d, matrix, i+1, j);
		}
		if(i > 0 && matrix[i-1][j] == 0) {
			path[(i-1)*5+j] = 1;
			flood(path, d, matrix, i-1, j);
		}
	} else {
		return false;
	}
}

int main() {
	int matrix[5][5];
	int n;
	scanf("%d", &n);
	for(int k = 0; k < n; k++) {

		int path[25];
		int d[25];
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		for(int i = 0; i < 25; i++) {
			path[i] = 0;
			d[i] = 0;
		}
		path[0] = 1;
		flood(path, d, matrix, 0, 0);
		if(path[24] == 1) {
			cout << "COPS" << endl;
		} else {
			cout << "ROBBERS" << endl;
		}

	}
	return 0;

}