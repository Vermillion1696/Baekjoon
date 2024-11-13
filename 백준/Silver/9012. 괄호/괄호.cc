#include <iostream>
#include <stack>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	stack<char> s;
	string str;

	while (tc--) {
		cin >> str;

		bool balanced = true;
		stack<char> s;

		for (auto c : str) {
			if (c == '(') s.push('(');
			else {
				if (s.empty()) {
					balanced = false;
					break;
				}
				else s.pop();
			}
		}

		if (!s.empty()) balanced = false;

		cout << (balanced ? "YES" : "NO") << endl;
	}
}