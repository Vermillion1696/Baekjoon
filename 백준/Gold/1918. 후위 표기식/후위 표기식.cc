#include <iostream>
#include <stack>    
using namespace std;

// 연산자에 따른 우선순위 반환
int precedence(const char op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int main() {
	stack<char> s;
	string str;
	cin >> str;

	for (auto& iter : str) {
		if ('A' <= iter && iter <= 'Z') {
			cout << iter;
		}
		else if (iter == '(') {
			s.push(iter);
		}
		else if (iter == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else { // operators
			while (!s.empty() && precedence(s.top()) >= precedence(iter)) {
				cout << s.top();
				s.pop();
			}
			s.push(iter);
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}