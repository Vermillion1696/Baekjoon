#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 선언
	stack<int> s;
	int n, c;
	cin >> n;

	// 조건문
	while (n--) {
		cin >> c;

		// case 1 : push
		if (c == 1) {
			int temp;
			cin >> temp;
			s.push(temp);
		}
		// case 2 : top && pop
		else if (c == 2) {
			if (s.size() > 0) {
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		// case 3 : size
		else if (c == 3) {
			cout << s.size() << "\n";
		}
		// case 4 : empty
		else if (c == 4) {
			cout << s.empty() << "\n";
		}
		// case 5 : top
		else if (c == 5) {
			if (s.size() > 0) {
				cout << s.top() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}