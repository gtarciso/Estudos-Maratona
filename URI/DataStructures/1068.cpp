#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int size;
	string str;
	while(getline(cin, str)) {
		size = str.length();
		stack<char> stk;
		for(int i = 0; i < size; i++) {
			if(str[i] == '(')
				stk.push(i);
			if(str[i] == ')')
				if(!stk.empty())
					stk.pop();
				/*
					this else is needed cuz we can have a situation like ') ()'
				*/
				else
					stk.push(i);
		}
		if(stk.empty())
			cout << "correct" << endl;
		else
			cout << "incorrect" << endl;
	}
	return 0;
}