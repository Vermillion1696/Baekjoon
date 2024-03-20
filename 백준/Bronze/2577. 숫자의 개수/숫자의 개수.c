#include<stdio.h>
int main() {
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	// 3개의 자연수 입력 받기

	int totalnumber = a * b * c;
	// 곱한 결과인 문자 만들기

	int timesarr[10];
	for (int i = 0; i < 10; i++) {
		timesarr[i] = 0;
	}
	// 0~9까지 몇 번 썼는지 표현할 배열 만들기

	int temp = 0;
	for (int i = 0; totalnumber != 0; i++) {
		temp = totalnumber % 10;
		totalnumber /= 10;
		for (int j = 0; j < 10; j++) {
			if (temp == j) {
				timesarr[j]++;
			}
		}
	}
	// 10으로 나눈 나머지를 이용해 횟수 더하기

	for (int i = 0; i < 10; i++) {
		printf("%d\n", timesarr[i]);
	}

	return 0;
}