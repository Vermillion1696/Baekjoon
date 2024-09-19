#include <iostream>
using namespace std;

int dp[100001];

int main() {

	// 초기 설정, 제곱수인경우
	for (int i = 1; i * i <= 100000; i++) {
		dp[i * i] = 1;
	}

	// dp 채우기
	for (int i = 1; i <= 100000; i++) {
		
		// 기본 케이스 : 이전 + 1
		if (dp[i] != 1) dp[i] = dp[i - 1] + 1;

		for (int j = 2; j * j <= 100000; j++) {
			
			// 인덱스가 0 또는 음수 되는 경우 break;
			if (i <= j * j) break;

			// 더 작은 값을 취함
			// ex. dp[5] = min(dp[4] + 1, dp[1] + 1);
			// (4까지 + 9) or (1까지 + 4) -> 4, 9 둘 다 제곱수이므로 + 1
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	int n;
	cin >> n;
	cout << dp[n];

	return 0;
}