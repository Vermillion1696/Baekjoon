#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0, val;
	while (n--) {
		cin >> val;
		if (val % 2 == 1) cnt++;
	}

	cout << cnt;

	return 0;
}