#include <iostream>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
ll dp[501][501];

int main() {
	fast_output;

	int size, value;
	cin >> size;

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> value;

			// 맨 윗 층 (7)
			if (i == 1) {
				dp[1][1] = value;
			}

			// 맨 왼쪽 (3, 8, 2, 4, ...)
			else if (j == 1) {
				dp[i][j] = dp[i - 1][j] + value;
			}

			// 맨 오른쪽 (8, 0, 4, 5, ...)
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + value;
			}

			// 나머지
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value;
			}
		}
	}
	
	// 디버깅용 출력
	/*
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	ll maximum = 0;
	for (int dir = 1; dir <= size; dir++) {
		maximum = max(maximum, dp[size][dir]);
	}

	cout << maximum;
}