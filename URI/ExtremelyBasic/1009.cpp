#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {
	string nome;
	double salario, vendas;
	cin >> nome;
	scanf("%lf", &salario);
	scanf("%lf", &vendas);
	printf("TOTAL = R$ %.2lf\n", salario + vendas*0.15);
	return 0;
}