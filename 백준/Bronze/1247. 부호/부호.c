#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	// Group 구조체 선언
	typedef struct {
		int arr[30];
	} Group;

	// 양수 모음 Positive, 음수 모음 Negative
	Group Positive, Negative;

	// 세 번의 테스트 케이스 진행
	for (int testCase = 0; testCase < 3; testCase++) {

		// 각 테스트 케이스 진행 이전 양수/음수의 합 초기화
		for (int i = 0; i < 30; i++) {
			Positive.arr[i] = 0;
			Negative.arr[i] = 0;
		}

		// 입력 받을 정수의 개수
		int testSet;
		scanf("%d", &testSet);
		
		for (int j = 0; j < testSet; j++) {
			char str[25];
			scanf("%s", str);

			// 첫 문자가 - 이면 음수 그룹에 더하기
			if (str[0] == '-') {
				for (int k = 1; str[k] != NULL; k++) {
					Negative.arr[strlen(str) - k - 1] += str[k] - '0';
				}
			} // 아니면 양수 그룹에 더하기
			else {
				for (int k = 0; k < strlen(str); k++) {
					Positive.arr[strlen(str) - k - 1] += str[k] - '0';
				}
			}
		}

		// 10 진법 이므로 각 자리 수에 해당하는 배열 원소가 10을 넘으면 캐리 보내기
		for (int i = 0; i < 29; i++) {
			if (Positive.arr[i] / 10 > 0) {
				Positive.arr[i + 1] += (Positive.arr[i] / 10);
				Positive.arr[i] %= 10;
			}
			if (Negative.arr[i] / 10 > 0) {
				Negative.arr[i + 1] += (Negative.arr[i] / 10);
				Negative.arr[i] %= 10;
			}
		}

		// same은 boolean, 29번 (제일 높은 자리) 부터 0번 자리까지 검사 후 != 이면 same = 0 반환
		int same = 1;
		for (int i = 29; i >= 0; i--) {
			if (Positive.arr[i] > Negative.arr[i]) {
				printf("+\n");
				same = 0;
				break;
			}
			else if (Positive.arr[i] < Negative.arr[i]) {
				printf("-\n");
				same = 0;
				break;
			}
		}

		// same == 1이면 0이므로 0 출력
		if (same == 1) {
			printf("0\n");
		}
	}

	return 0;
}