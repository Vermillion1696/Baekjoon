#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	// Group 구조체 선언
	typedef struct {
		int arr[10101];
	} Group;

	// 양수 모음 Positive, 음수 모음 Negative, A + B 저장 Total
	Group Positive, Negative, Total;

	// 각 테스트 케이스 진행 이전 양수/음수의 합 초기화
	for (int i = 0; i < 10101; i++) {
		Positive.arr[i] = 0;
		Negative.arr[i] = 0;
		Total.arr[i] = 0;
	}

	for (int times = 0; times < 2; times++) {
		char str[10101];
		scanf("%s", str);

		// 첫 문자가 - 이면 음수 그룹에 더하기
		if (str[0] == '-') {
			for (int k = 1; k < strlen(str); k++) {
				Negative.arr[strlen(str) - k - 1] += str[k] - '0';
			}
		} // 아니면 양수 그룹에 더하기
		else {
			for (int k = 0; k < strlen(str); k++) {
				Positive.arr[strlen(str) - k - 1] += str[k] - '0';
			}
		}

		// 10 진법 이므로 각 자리 수에 해당하는 배열 원소가 10을 넘으면 캐리 보내기
		for (int i = 0; i < strlen(str); i++) {
			if (Positive.arr[i] / 10 > 0) {
				Positive.arr[i + 1] += (Positive.arr[i] / 10);
				Positive.arr[i] %= 10;
			}
			if (Negative.arr[i] / 10 > 0) {
				Negative.arr[i + 1] += (Negative.arr[i] / 10);
				Negative.arr[i] %= 10;
			}
		}
	}

	// same은 boolean, 10001번 (제일 높은 자리) 부터 0번 자리까지 검사 후 != 이면 same = 0 반환
	int same = 1;
	char integer;
	for (int i = 10001; i >= 0; i--) {
		if (Positive.arr[i] > Negative.arr[i]) {
			integer = '+';
			same = 0;
			break;
		}
		else if (Positive.arr[i] < Negative.arr[i]) {
			integer = '-';
			same = 0;
			break;
		}
	}

	// same == 1이면 0이므로 0 출력
	if (same == 1) {
		integer = '0';
	}

	// 부호에 따라 절댓값 큰 것 - 절댓값 작은 것
	if (integer == '+') {
		for (int i = 10001; i >= 0; i--) {
			Total.arr[i] = (Positive.arr[i] - Negative.arr[i]);
		}
	}
	else if (integer == '-') {
		for (int i = 10001; i >= 0; i--) {
			Total.arr[i] = (Negative.arr[i] - Positive.arr[i]);
		}
	}

	// Total 캐리 내림
	for (int i = 10001; i > 0; i--) {
		if (Total.arr[i - 1] < 0) {
			Total.arr[i]--;
			Total.arr[i - 1] += 10;
		}
	}

	// 0이 아니면 
	if (same == 0) {

		// 음수면 맨 앞에 - 붙이고
		if (integer == '-') {
			printf("-");
		}

		// 앞의 0들은 출력 X
		int zeroChecker = 0;
		for (int i = 10001; i >= 0; i--) {
			if (Total.arr[i] != 0) {
				zeroChecker++;
			}

			if (zeroChecker > 0) {
				printf("%d", Total.arr[i]);
			}
		}
	}
	else {
		printf("0");
	}

	return 0;
}