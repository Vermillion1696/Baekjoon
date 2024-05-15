#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	// 입력
	int arr[300000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n == 0) {
		cout << 0;
		return 0;
	}

	// 정렬
	sort(arr, arr + n);

	// 앞, 뒤에서 자를 인원 수 temp (floor 함수에 0.5 더하면 반올림)
	int temp = floor(double(n) * 0.15 + 0.5);
	double total = 0;

	// total은 평균을 구할 수
	for (int i = temp; i < n - temp; i++) {
		total += arr[i];
	}

	// 반올림 처리 후 출력
	cout << floor(total / (n - 2 * temp) + 0.5);

	return 0;
}