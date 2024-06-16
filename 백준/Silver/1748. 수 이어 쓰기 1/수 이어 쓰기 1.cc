#include <iostream>
using namespace std;
typedef long long ll;

ll pow(int a, int b) {
	ll total = 1;
	for (int i = 0; i < b; i++) {
		total *= a;
	}
	return total;
}

int main() {
	// 1~9 : 1
	// 10~99 : 2 -> 1~90
	// 100~999 : 3 -> 1~900

	int n;
	cin >> n;
	ll total = 0;
	int cnt = 1;

	while (n > 0) {
		if (n > 9 * pow(10, cnt - 1)) {
			total += cnt * 9 * pow(10, cnt - 1);
		}
		else {
			total += cnt * n;
		}
		n -= 9 * pow(10, cnt - 1);
		cnt++;
	}
	
	cout << total;

	return 0;
}