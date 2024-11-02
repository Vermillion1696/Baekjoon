#include <iostream>
#define fast_io cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast_io;

	int tc;
	cin >> tc;

	string num;
	while (tc--) {
		cin >> num;

		long long digit_sum = 0;
		for (auto iter : num) {
			digit_sum += iter - '0';
		}

		if (digit_sum % 9 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}