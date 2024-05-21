#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> s;
	int tc;
	cin >> tc;
	cin.ignore(); // 버퍼 비우기
		
	string str;
	while (tc--) {
		getline(cin, str);

		for (int i = 0; str[i] != NULL; i++) {
			if (str[i] != ' ') {
				s.push(str[i]);
			}
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}

		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}

		cout << "\n";
	}
	
	return 0;
}