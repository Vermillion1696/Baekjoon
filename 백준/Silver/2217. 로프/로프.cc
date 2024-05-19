#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
long long int maxSum[100000];

// <algorithm> 내장 sort() 인자 compare()
bool compare(int a, int b) {
	return a > b;
}

int main() {
	
	// 개수
	int n;
	cin >> n;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 정렬
	sort(arr, arr + n, compare);

	// 각 개수에 따른 최대 가능 무게 저장
	int index = 0;
	while (index < n) {
		maxSum[index] = arr[index] * (index + 1);
		index++;
	}

	// 최댓값 찾기
	long long int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < maxSum[i]) {
			max = maxSum[i];
		}
	}

	// 출력
	cout << max;

	return 0;
}