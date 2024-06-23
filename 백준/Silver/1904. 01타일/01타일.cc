#include <iostream>
using namespace std;

int dp[1000000];

int main() {
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	int n;
	cin >> n;
	cout << dp[n - 1];
}