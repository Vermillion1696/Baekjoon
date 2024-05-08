#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// <stdlib.h> 내장 함수 qsort 사용에 필요한 compare 함수 선언
int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	}
	else if (*(int*)a < *(int*)b) {
		return -1;
	}
	else {
		return 0;
	}
}

// 원소가 있으면 1, 없으면 0을 반환하는 binarySearch 이진 탐색 함수
int binarySearch(int arr[], int first, int last, int target) {

	if (first > last) {
		return 0;
	}

	int mid = (first + last) / 2;

	if (target == arr[mid]) {
		return 1;
	}
	else if (target > arr[mid]) {
		binarySearch(arr, mid + 1, last, target);
	}
	else {
		binarySearch(arr, first, mid - 1, target);
	}

}

int main() {
	int n;
	scanf("%d", &n);

	// array : 실제 배열
	int* array = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	int m;
	scanf("%d", &m);

	// compareArray : 있는지 확인할 원소들 배열
	int* compareArray = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		scanf("%d", &compareArray[i]);
	}

	// 퀵 정렬
	qsort(array, n, sizeof(int), compare);

	// compareArray의 각 원소가 있는지 없는지 출력
	for (int i = 0; i < m; i++) {
		printf("%d\n", binarySearch(array, 0, n - 1, compareArray[i]));
	}

	free(array);
	free(compareArray);
	return 0;
}