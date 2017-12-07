#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maiorAB(int a, int b) {
	return (a+b+abs(a-b))/2;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int maior = maiorAB(a, b);
	maior = maiorAB(maior, c);
	cout << maior << " eh o maior" << endl;
	return 0;

}