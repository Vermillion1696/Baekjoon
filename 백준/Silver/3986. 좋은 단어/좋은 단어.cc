#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 좋은 단어인지 체크 하는 함수
bool GoodWordChecker(string& str, int& length) {
	stack<char> s;

	for (int i = 0; i < length; i++) {
		if (s.empty()) {
			s.push(str[i]);
		}
		else if (s.top() == str[i]) {
			s.pop();
		}
		else {
			s.push(str[i]);
		}
	}

	if (s.empty()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int tc;
	cin >> tc;

	string str;
	int length;
	int cnt = 0;
	while (tc--) {
		cin >> str;
		length = str.length();
		
		if (GoodWordChecker(str, length)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}