#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int** arr = (int**)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		arr[i] = (int*)malloc(b * sizeof(int));
	} // 이차원 배열 동적 할당

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			arr[i][j] = 0;
		}
	} // 행렬 초기화

	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int temp;
				scanf("%d", &temp);
				arr[i][j] += temp;
			}
		}
	} // t >> 행렬 A, B (2번) 받음, i&j >> 행렬의 각 원소

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < a; i++) {
		free(arr[i]);
	}
	free(arr);
	// 동적 할당 메모리 해제

	return 0;
}