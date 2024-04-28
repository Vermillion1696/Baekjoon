#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

	int arr[20];
	for (int i = 0; i < 20; i++) {
		arr[i] = i + 1;
	} // 배열 세팅

	for (int i = 0; i < 10; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int times;
		if ((b - a) % 2 == 1) {
			times = ((b - a) / 2) + 1;
		}
		else {
			times = (b - a) / 2;
		} // 변환 횟수 정하기

		for (int j = 0; j < times; j++) {
			int temp = arr[a - 1 + j];
			arr[a - 1 + j] = arr[b - 1 - j];
			arr[b - 1 - j] = temp;
		} // 내림차순 재배열
	}

	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}