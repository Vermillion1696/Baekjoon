#include <iostream>
#include <algorithm>
using namespace std;

// <algorithm> 내장 sort 함수 인자 compare()
int compare(int a, int b) {
	return a > b;
}

int main() {

	// 입력
	int n, k;
	cin >> n >> k;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 정렬
	sort(arr, arr + n, compare);

	// k번째 원소 출력
	cout << arr[k - 1];

	return 0;
}