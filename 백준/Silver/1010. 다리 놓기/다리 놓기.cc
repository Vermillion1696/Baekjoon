#include <iostream>
using namespace std;
long long int dp[30][30];

int main() {

	// iCj의 값을 파스칼의 삼각형을 이용해 dp[i][j]에 저장
	// 먼저, iCi와 iC0은 모두 1
	for (int i = 0; i < 30; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	// 2C1부터 29C28까지
	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < 29; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int tc, n, r;
	cin >> tc;

	while (tc--) {
		cin >> r >> n;
		cout << dp[n][r] << "\n";
	}

	return 0;
}