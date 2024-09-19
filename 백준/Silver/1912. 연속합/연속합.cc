#include <iostream>
using namespace std;
using ll = long long int;

// dp[n]: n번째 위치에서의 최대 연속 합
ll dp[100001];
ll num[100001];

int main() {
	int n;
	cin >> n;

	// 입력
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	dp[1] = num[1];
	ll max_dp = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(num[i], dp[i - 1] + num[i]);
		max_dp = max(max_dp, dp[i]);
	}

	cout << max_dp;

	return 0;
}