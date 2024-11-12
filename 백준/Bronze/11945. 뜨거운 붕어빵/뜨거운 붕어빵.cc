#include <iostream>
#include <stack>
using namespace std;

int main() {
	int tc, length;
	cin >> tc >> length;

	char c;
	while (tc--) {
		stack<char> s;
		for (int i = 0; i < length; i++) {
			cin >> c;
			s.push(c);
		}

		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}

		cout << '\n';
	}

	return 0;
}