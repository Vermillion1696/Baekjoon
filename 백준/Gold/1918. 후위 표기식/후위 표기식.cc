// 2학년 2학기 자료구조 중간고사 대비겸 연습 문제
/*
하단 로직을 구현했음을 알립니다.

while (unless there is no more input to read)

- if the next input is a left parenthesis

	→  push it onto the stack

- else if the next input is a number or a variable

	→ write it to the output

- else if the next input is an operator

	→ do { print the top operator and pop it } while (**none** of **these three conditions** are true…);

	1. the stack becomes **empty**.
	2. the top item on the stack is a **left parenthesis**.
	3. the top item on the stack is an operator with **lower precedence than the input operator**.

	→ push the input operator onto the stack.

- else (the next input is a right parenthesis)

	→ write the top item(operator) and pop it off the stack.

	→ keep printing and popping until a left parenthesis is the top item on the stack and then pop the ‘(’.


print and pop any remaining operators on the stack.
*/

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