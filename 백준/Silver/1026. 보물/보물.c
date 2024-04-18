#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 배열 A를 작은 순, 배열 B를 큰 순으로 배치하면 total의 최솟값이 나온다
int main() {
	int n;
	scanf("%d", &n);

	int arrA[50];
	int arrB[50];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arrA[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrB[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arrA[j] > arrA[j + 1]) {
				int temp = arrA[j];
				arrA[j] = arrA[j + 1];
				arrA[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arrB[j] < arrB[j + 1]) {
				int temp = arrB[j];
				arrB[j] = arrB[j + 1];
				arrB[j + 1] = temp;
			}
		}
	}

	long long int total = 0;
	for (int i = 0; i < n; i++) {
		total += (arrA[i] * arrB[i]);
	}

	printf("%lld", total);
	return 0;
}