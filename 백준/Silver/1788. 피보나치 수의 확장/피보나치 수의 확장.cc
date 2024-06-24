#include <iostream>
using namespace std;
long long int dp[1000000];

int main() {

	// 피보나치 수열 dp
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}

	int n;
	cin >> n;

	// 음수 부분은 abs(n) % 2 == 0 인 경우만 dp[n]이 음수이다.
	if (n == 0) {
		cout << 0 << "\n";
	}
	else if (n < 0 && (n * (-1)) % 2 == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << 1 << "\n";
	}

	n < 0 ? n *= -1 : n *= 1;

	cout << dp[n];

	return 0;
}