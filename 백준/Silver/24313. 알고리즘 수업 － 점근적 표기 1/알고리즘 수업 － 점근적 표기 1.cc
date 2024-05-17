#include <iostream>
using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	
	// a1 * n + a0 <= c * n 이 모든 n0 <= n 에 대해 만족 ?
	// -> a0 / (c - a1) <= n, a0 / (c - a1) <= n0 이면 true

	if (c == a1) {
		cout << 1;
		return 0;
	}
	else {
		if (a0 / (c - a1) <= n0 && a1 <= c) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}

	return 0;
}