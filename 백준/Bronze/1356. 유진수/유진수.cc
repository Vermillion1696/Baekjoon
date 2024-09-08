#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	// 한 자리 수는 어떤 경우에도 불가능이므로 예외처리
	int length = str.length();
	if (length == 1) {
		cout << "NO";
		return 0;
	}

	// 중간 포인트 순회
	for (int middle = 0; middle < length; middle++) {
		int left_total = 1, right_total = 1;

		// 왼쪽 곱
		for (int dir = 0; dir < middle; dir++) {
			left_total *= str[dir] - '0';
		}

		// 오른쪽 곱
		for (int dir = middle; dir < length; dir++) {
			right_total *= str[dir] - '0';
		}

		// cout << left_total << ' ' << right_total << '\n';
		if (left_total == right_total) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}