#include <iostream>
#include <vector>
using namespace std;

// 한수인지 판별하는 함수
bool sequence(int n) {

	// 한 자리 수는 무조건 한수 (전처리)
	if (n < 10) {
		return 1;
	}

	vector<int> v;

	// 각 자리 숫자 벡터에 입력
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	bool hansu = true;
	int size = v.size();
	int gap;

	// 한수 판별
	for (int i = 0; i < size - 1; i++) {
		gap = v[0] - v[1];

		if (gap != v[i] - v[i + 1]) {
			hansu = false;
			break;
		}
	}

	if (hansu) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (sequence(i)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}