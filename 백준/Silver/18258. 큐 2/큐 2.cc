#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 선언
	queue<int> q;
	string str;
	int n;
	cin >> n;

	// 조건문
	while (n--) {
		cin >> str;

		// case 1 : push
		if (str.compare("push") == 0) {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		// case 2 : top && pop
		else if (str.compare("pop") == 0) {
			if (q.size() > 0) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		// case 3 : size
		else if (str.compare("size") == 0) {
			cout << q.size() << "\n";
		}
		// case 4 : empty
		else if (str.compare("empty") == 0) {
			cout << q.empty() << "\n";
		}
		// case 5 : front
		else if (str.compare("front") == 0) {
			if (q.size() > 0) {
				cout << q.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		// case 6 : back
		else if (str.compare("back") == 0) {
			if (q.size() > 0) {
				cout << q.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}