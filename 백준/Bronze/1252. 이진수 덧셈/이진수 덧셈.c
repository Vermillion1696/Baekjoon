#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	// 배열 받을 구조체
	typedef struct {
		char str[100];
	} Binary;

	// 이진수 1, 이진수 2, 최종 합
	Binary first, second;
	int total[100];
	for (int i = 0; i < 100; i++) {
		total[i] = 0;
	}

	scanf("%s", first.str);
	scanf("%s", second.str);

	// 배열 자리 값 더하기
	for (int i = 99; i >= 100 - strlen(first.str); i--) {
		total[strlen(first.str) - 1 + (i - 99)] += (first.str[99 - i] - '0');
	}
	for (int i = 99; i >= 100 - strlen(second.str); i--) {
		total[strlen(second.str) - 1 + (i - 99)] += (second.str[99 - i] - '0');
	}
	
	// 캐리 올림 연산
	for (int i = 0; i < 100; i++) {
		if (total[i] > 1) {
			total[i + 1] += (total[i] / 2);
			total[i] %= 2;
		}
	}
	
	// 0 제외 출력
	int zeroCount = 0;
	for (int i = 99; i >= 0; i--) {
		if (total[i] != 0) {
			zeroCount++;
		}
		if (zeroCount != 0) {
			printf("%d", total[i]);
		}
	}

	// 둘 다 0이면 0 출력
	if (zeroCount == 0) {
		printf("0");
	}

	return 0;
}