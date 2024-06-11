#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc, n, five;
	cin >> tc;

	while (tc--) {
		five = 0;

		cin >> n;

		for (int i = 5; i <= n; i *= 5) {
			five += n / i;
		}

		cout << five << "\n";
	}

	return 0;
}