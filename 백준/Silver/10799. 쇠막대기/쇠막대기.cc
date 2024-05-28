#include <iostream>
#include <stack>
using namespace std;

int laser(string& str) {
	stack<char> s;
	int total = 0;
	char char_prev = 'A';

	// 문자열을 끝까지 돌 때까지
	for (int i = 0; i < str.length(); i++) {

		// str[i]가 (이면 push
		if (str[i] == '(') {
			s.push(str[i]);
		}
		// str[i] 이전이 )이고 str[i]도 )이면
		// s.size()-- && total++
		else if (char_prev == ')' && str[i] == ')') {
			s.pop();
			total++;
		}
		// str[i]가 )이고 s.top()이 (이면 레이저를 쏜다
		else {
			s.pop();
			total += s.size();
		}

		char_prev = str[i];
	}

	return total;
}

int main() {
	string str;
	cin >> str;

	cout << laser(str);

	return 0;
}