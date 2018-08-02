#include <stdio.h>
#include <string.h>

using namespace std;

void pop1(int index, char str[]) {
	while(1) {
		str[index] = str[index+1];
		index++;
		if(str[index] == 'x') break;
	}
}

void pop2(int index, char str[]) {
	pop1(index, str);
	pop1(index+1, str);
}

int main() {
	int n;
	scanf("%d", &n);
	char str[1002];
	for(int i = 0; i < n; i++) {
		getchar();
		memset(str, 'x', sizeof(str[0])*1002);
		char c = 'a';
		int direita  = 0;
		int esquerda = 0;
		int index = 0;
		while(c != '\n') {
			scanf("%c", &c);
			str[index] = c;
			index++;
		}
		int j = 0;
		int cont = 0;
		while(str[j] != 'x') {
			if(str[j] == '.') {
				pop1(j, str);
			}
			if(str[j] == '<' && str[j+1]) {
				pop2(j, str);
				cont++;
			}
			j++;
		}

		printf("%d\n", cont);

	}
	return 0;
}