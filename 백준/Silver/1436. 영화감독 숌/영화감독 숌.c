#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 두 개의 정렬된 배열을 합병하는 함수
void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// 임시 배열 생성
	int* L = (int*)malloc(sizeof(int) * n1);
	int* R = (int*)malloc(sizeof(int) * n2);

	// 임시 배열에 데이터 복사
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// 임시 배열을 합병하여 원래 배열에 저장
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// 남은 요소들 복사
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	// 임시 배열 해제
	free(L);
	free(R);
}

// 병합 정렬 함수
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		// 분할 후 정렬
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// 정렬된 두 배열 합병
		merge(arr, left, mid, right);
	}
}

int main() {
	int arr[49000];

	arr[0] = 666;
	// ~ 3자리

	for (int i = 1; i <= 9; i++) {
		arr[i] = i * 1000 + 666; // arr[9]까지
	}
	for (int i = 0; i <= 9; i++) {
		arr[10 + i] = 666 * 10 + i; // arr[19]까지
	}
	// ~ 4자리

	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[20 + 10 * (i - 1) + j] = i * 10000 + j * 1000 + 666;  // arr[109]까지
			arr[110 + 10 * (i - 1) + j] = i * 10000 + 666 * 10 + j; // arr[199]까지
		}
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[200 + 10 * i + j] = 666 * 100 + i * 10 + j; // arr[299]까지
		}
	}
	// ~ 5자리

	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				arr[300 + 100 * (i - 1) + 10 * j + k] = i * 100000 + j * 10000 + k * 1000 + 666;
				arr[1200 + 100 * (i - 1) + 10 * j + k] = i * 100000 + j * 10000 + 666 * 10 + k;
				arr[2100 + 100 * (i - 1) + 10 * j + k] = i * 100000 + 666 * 100 + j * 10 + k;
			}
		}
	} // arr[2999]까지
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				arr[3000 + 100 * i + 10 * j + k] = 666 * 1000 + i * 100 + j * 10 + k;
			}
		}
	} // arr[4000]까지
	// ~6자리

	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int m = 0; m <= 9; m++) {
					arr[4000 + 1000 * (i - 1) + 100 * j + 10 * k + m] = i * 1000000 + j * 100000 + k * 10000 + m * 1000 + 666;
					arr[13000 + 1000 * (i - 1) + 100 * j + 10 * k + m] = i * 1000000 + j * 100000 + k * 10000 + 666 * 10 + m;
					arr[22000 + 1000 * (i - 1) + 100 * j + 10 * k + m] = i * 1000000 + j * 100000 + 666 * 100 + k * 10 + m;
					arr[31000 + 1000 * (i - 1) + 100 * j + 10 * k + m] = i * 1000000 + 666 * 1000 + j * 100 + k * 10 + m;
				}
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int m = 0; m <= 9; m++) {
					arr[40000 + 1000 * (i - 1) + 100 * j + 10 * k + m] = 666 * 10000 + i * 1000 + j * 100 + k * 10 + m;
				}
			}
		}
	} // arr[48999]까지
	// ~ 7자리

	mergeSort(arr, 0, 48999);
	// 오름차순 정렬

	for (int i = 0; i < 48999; i++) {
		if (arr[i] == arr[i + 1]) {
			arr[i] = 99999999;
		}
	}
	mergeSort(arr, 0, 48999);
	// 중복 숫자는 8자리로 바꾸고 다시 오름차순 정렬로 맨 뒤로 빼기

	int n;
	scanf("%d", &n);
	printf("%d", arr[n - 1]);

	return 0;
}