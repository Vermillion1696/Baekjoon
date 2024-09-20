#include <iostream>
#include <iomanip>
using namespace std;

long double dp[10000];
long double va[10000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> va[i];
	}

	// dp
	dp[0] = va[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] * va[i], va[i]);
	}

	// 최대 찾기
	long double max_val = 0.0;
	for (int i = 0; i < n; i++) {
		max_val = max(max_val, dp[i]);
	}

	cout << fixed << setprecision(3) << max_val;

	return 0;
}