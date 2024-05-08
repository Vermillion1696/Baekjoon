#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// point : 8진수 1개 -> 2진수 3개로 표현 가능

int main() {
	char arr[400000];
	// 수의 길이가 333,334 이하이므로 배열로 받음

	scanf("%s", arr);

	for (int i = 0; arr[i] != NULL; i++) {
		int temp = arr[i] - '0';

		// 입력이 0인 경우
		if (temp == 0 && i == 0) {
			printf("0");
			break;
		}

		int binaryArr[3];

		for (int i = 0; i < 3; i++) {
			binaryArr[i] = temp % 2;
			temp /= 2;
		} // 각 숫자의 2진수 적기

		// 첫 숫자일 때는 맨 앞이 1일때부터 출력
		if (i == 0) {
			int location = 2;
			for (int i = 2; i >= 0; i--) {
				if (binaryArr[i] == 0) {
					location--;
				}
				else {
					break;
				}
			}

			for (int i = location; i >= 0; i--) {
				printf("%d", binaryArr[i]);
			}
		}
		else {
			for (int i = 2; i >= 0; i--) {
				printf("%d", binaryArr[i]);
			}
		}
	}

	return 0;
}