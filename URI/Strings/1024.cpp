#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
	string str;
	int size, n;
	scanf("%d ", &n);
	//cin.ignore();
	for(int i = 0; i < n; i++) {
		getline(cin, str); 
		size = str.length();
		for(int j = 0; j < size; j++) {
			if((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z'))
				str[j]+=3;
		}
		char *aux = new char[1050];
		for(int j = 0, k = size-1; j < size; j++, k--) {
			aux[j] = str[k];
		}
		int j;
		for(int j = size/2; j < size; j++) {
			aux[j]--;
		}
		printf("%s\n", aux);
	}
	return 0;

}