#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	double l;
	while(cin >> l) {
		double area = l * l * (sqrt(3.0)/4.0);
		area *= 1.6;
		printf("%.2lf\n", area);
	}
}
