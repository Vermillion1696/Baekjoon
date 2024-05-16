#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	// string 선언
	string str;

	while (1) {

		// 참 거짓 판별 tf, <string> 내장 공백 포함 입력 받기 getline(), 스택 s
		bool tf = 1;
		getline(cin, str);
		stack <int> s;

		// string의 첫 문자가 .이면 종료
		if (str[0] == '.') {
			return 0;
		}
		
		// NULL 문자를 만날 때까지
		for (int i = 0; str[i] != NULL; i++) {

			// str[i]가 괄호 시작 문자면 push
			if (str[i] == '[' || str[i] == '(') {
				s.push(str[i]);
			}
			// str[i]가 괄호 종료 문자인데 스택에 쌓인게 없으면 불가능 판정
			else if ((str[i] == ')' || str[i] == ']') && s.size() == 0) {
				tf = 0;
				break;
			}
			// str[i]가 괄호 종료 문자인데 스택 top이 다른 종류 시작 문자면 불가능 판정
			else if (str[i] == ']' && s.top() == '(' || str[i] == ')' && s.top() == '[') {
				tf = 0;
				break;
			}
			// str[i]가 괄호 종료 문자고 스택 top이 같은 종류 시작 문자면 top pop
			else if (str[i] == ']' && s.top() == '[' || str[i] == ')' && s.top() == '(') {
				s.pop();
			}
		}

		// 스택이 비어있고 (모든 괄호가 정상적 종료) && 오류 판정이 아니면
		if (s.size() == 0 && tf) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}