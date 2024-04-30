#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, sum;
	scanf("%d %d", &n, &sum);
	int arr[10];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= sum) {
			cnt += (sum / arr[i]);
			sum %= arr[i];
		}
	} // 큰 숫자부터, arr[i] <= sum 일때 카운트 증가

	printf("%d", cnt);
	return 0;
}