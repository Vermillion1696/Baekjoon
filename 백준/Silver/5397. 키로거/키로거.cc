#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main() {

	// 스택 1, 2, 테케
	stack<char> s1;
	stack<char> s2;
	int tc;
	cin >> tc;

	while(tc--) {
		
		// 문자열 입력
		string str;
		cin >> str;

		for (int i = 0; str[i] != NULL; i++) {

			// > 인 경우 s2에 있던 원소를 s1에 옮김
			if (str[i] == '>') {
				if (!s2.empty()) {
					s1.push(s2.top());
					s2.pop();
				}
			}
			// < 인 경우 s1에 있던 원소를 s2에 옮김
			else if (str[i] == '<') {
				if (!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
			}
			// - 인 경우 s1의 top을 pop
			else if (str[i] == '-') {
				if (!s1.empty()) {
					s1.pop();
				}
			}
			// 아니면 push
			else {
				s1.push(str[i]);
			}
		}

		// s2의 모든 원소 s1에 담기
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		// dq에 back으로 s1의 원소 다 넣기
		deque<char> dq;
		while (!s1.empty()) {
			dq.push_back(s1.top());
			s1.pop();
		}

		// queue이므로 dq를 back으로 출력
		while (!dq.empty()) {
			cout << dq.back();
			dq.pop_back();
		}

		cout << "\n";
	}

	return 0;
}