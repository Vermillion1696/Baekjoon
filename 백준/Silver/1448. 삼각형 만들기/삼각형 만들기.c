#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return -1;
	}
	else if (*(int*)a < *(int*)b) {
		return 1;
	}
	else {
		return 0;
	}
} // <stdlib.h> 내부 qsort 함수에 필요한 compare 함수

int arr[1010101];
// n의 max가 1,000,000 이므로 main 외부 선언

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);
	// 퀵 정렬

	int tf = 0;
	for (int i = 0; i < n - 2; i++) {
		if (arr[i] < arr[i + 1] + arr[i + 2]) {
			printf("%d", arr[i] + arr[i + 1] + arr[i + 2]);
			tf = 1;
			break;
		}
	} // 제일 위부터 3개를 잡고 삼각형 조건 만족시 위 조합으로 결정

	if (tf == 0) {
		printf("-1");
	} // 만족하는 조합이 없을 경우 return -1

	return 0;
}