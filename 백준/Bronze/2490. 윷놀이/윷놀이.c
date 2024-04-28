#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[3][4];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	} // 4x3 이차원 배열에 값 저장


	int zeroCount = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				zeroCount++;
			}
		}

		if (zeroCount == 0) {
			printf("E\n");
		}
		else if (zeroCount == 1) {
			printf("A\n");
		}
		else if (zeroCount == 2) {
			printf("B\n");
		}
		else if (zeroCount == 3) {
			printf("C\n");
		}
		else {
			printf("D\n");
		}

		zeroCount = 0;
	}

	return 0;
}