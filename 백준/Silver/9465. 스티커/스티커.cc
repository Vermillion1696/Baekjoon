#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][100000];
int dp[2][100000];

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		if (n == 1) {
			cout << max(arr[0][0], arr[1][0]) << '\n';
			continue;
		}

		// 처음 값
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		// 점화식
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		// 출력
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}