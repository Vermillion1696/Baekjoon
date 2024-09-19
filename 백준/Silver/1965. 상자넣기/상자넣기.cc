#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	// 입력
	int n;
	cin >> n;
	vector<int> sizes(n);
	for (int i = 0; i < n; ++i) {
		cin >> sizes[i];
	}

	// 아무리 길이가 적아도 자기 자신은 포함
	// -> dp를 1로 초기화
	vector<int> dp(n, 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (sizes[j] < sizes[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = *max_element(dp.begin(), dp.end());
	cout << result;

	return 0;
}