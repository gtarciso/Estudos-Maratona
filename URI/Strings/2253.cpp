#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string pswd;
	int size;
	while(getline(cin, pswd)) {
		int flagUpper = 0, flagLower = 0, flagNumber = 0, flagInvalid = 0;
		size = pswd.length();
		if(size < 6 || size > 32) {
			cout << "Senha invalida." << endl;
			continue;
		}
		for(int i = 0; i < size; i++) {
			if ((pswd[i] < 'a' || pswd[i] > 'z') && (pswd[i] < 'A' || pswd[i] > 'Z') && (pswd[i] < '0' || pswd[i] > '9')) {
				flagInvalid = 1;
				break;
			}
			if(pswd[i] >= 'a' && pswd[i] <= 'z') {
				flagLower = 1;
			}
			if(pswd[i] >= 'A' && pswd[i] <= 'Z') {
				flagUpper = 1;
			}
			if(pswd[i] >= '0' && pswd[i] <= '9') {
				flagNumber = 1;
			}
		}
		if(flagNumber == 1 && flagUpper == 1 && flagLower == 1 && flagInvalid == 0) {
			cout << "Senha valida." << endl;
		} else {
			cout << "Senha invalida." << endl;
		}
	}
	return 0;
	
}