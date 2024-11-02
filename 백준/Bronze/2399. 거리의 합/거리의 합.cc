#include <iostream>
#include <vector>
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ret = x[i] - x[j];
			if (ret < 0) ret *= -1;
			sum += ret;
		}
	}

	cout << sum * 2;

	return 0;
}