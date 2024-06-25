#include <iostream>
using namespace std;
int dp[50];

int main() {
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < 50; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
	return 0;
}