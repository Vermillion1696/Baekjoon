#include <iostream>
using namespace std;

// n, 0으로 끝나는지 1로 끝나는지
long long int dp[100][2];

int main() {

	// 초기값
	dp[1][0] = 0;
	dp[1][1] = 1;

	// dp[num][0] (다음 0으로 끝나는 수)
	// = (이전 0으로 끝나는 수 + 0) + (이전 1로 끝나는 수 + 0)
	// dp[num][1] (다음 1로 끝나는 수)
	// = (이전 0으로 끝나는 수 + 1)
	for (int num = 2; num <= 90; num++) {
		dp[num][0] += dp[num - 1][0] + dp[num - 1][1];
		dp[num][1] += dp[num - 1][0];
	}
	
	int n;
	cin >> n;

	cout << dp[n][0] + dp[n][1];

	return 0;
}