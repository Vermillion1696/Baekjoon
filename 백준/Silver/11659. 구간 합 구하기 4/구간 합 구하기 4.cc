#include <iostream>
using namespace std;

long long int arr[100000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m, number;
	cin >> n >> m >> number;

	// arr[n]은 n번째 수 까지의 합을 저장
	arr[0] = number;
	for (int i = 1; i < n; i++) {
		cin >> number;
		arr[i] = arr[i - 1] + number;
	}

	// ex. 3~7번 까지의 합 == 1~7번 까지의 합 - 1~2번 까지의 합 == arr[7-1] - arr[(3-1)-1]
	int i, j;
	while (m--) {
		cin >> i >> j;
		if (i == 1) {
			cout << arr[j - 1] << "\n";
		}
		else {
			cout << arr[j - 1] - arr[i - 2] << "\n";
		}
	}

	return 0;
}