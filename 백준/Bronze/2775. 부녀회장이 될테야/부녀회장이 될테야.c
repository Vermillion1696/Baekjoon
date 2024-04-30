#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[15][14];
	
	for (int i = 0; i < 15; i++) {
		arr[i][0] = 1;
	} // 모든 층의 1호는 1명이 산다

	for (int i = 0; i < 14; i++) {
		arr[0][i] = i + 1;
	} // 0층의 각 호는 번호만큼의 명수가 산다

	int sum;
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 14; j++) {
			sum = 0;
			for (int k = 0; k <= j; k++) {
				sum += arr[i - 1][k];
			}
			arr[i][j] = sum;
		}
	} // a층의 b호는 a-1층의 1호부터 b호까지 사람들의 수의 합이다

	int testCase, k, n;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", arr[k][n - 1]);
	}

	return 0;
}