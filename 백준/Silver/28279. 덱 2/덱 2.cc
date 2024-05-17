#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 선언
	deque<int> dq;
	int n, c;
	cin >> n;

	// 조건문
	while (n--) {
		cin >> c;

		// case 1 : push_front
		if (c == 1) {
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		// case 2 : push_back
		else if (c == 2) {
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		// case 3 : front && pop
		else if (c == 3) {
			if (dq.size() > 0) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
		}
		// case 4 : front && pop
		else if (c == 4) {
			if (dq.size() > 0) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
		}
		// case 5 : size
		else if (c == 5) {
			cout << dq.size() << "\n";
		}
		// case 6 : empty
		else if (c == 6) {
			cout << dq.empty() << "\n";
		}
		// case 7 : front
		else if (c == 7) {
			if (dq.size() > 0) {
				cout << dq.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		// case 8 : back
		else if (c == 8) {
			if (dq.size() > 0) {
				cout << dq.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}