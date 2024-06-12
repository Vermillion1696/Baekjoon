#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	string str;
	queue<char> q;

	while (tc--) {
		cin >> str;
		q.push(str[0]);

		for (int i = 1; i < str.length(); i++) {
			if (q.back() != str[i]) {
				q.push(str[i]);
			}
		}

		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << "\n";
	}

	return 0;
}