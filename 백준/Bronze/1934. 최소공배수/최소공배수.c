#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testCase;
	scanf("%d", &testCase);
	// 테스트 케이스

	for (int i = 0; i < testCase; i++) {
		int a, b;
		int arrA[20000], arrB[20000];
		scanf("%d %d", &a, &b);

		int countA = 0;

		for (int j = 2; j <= a; j++) {
			while (1) {
				if (a % j == 0) {
					arrA[countA] = j;
					countA++;
					a /= j;
				}
				else {
					break;
				}
			}
		} // A의 약수

		int countB = 0;
		for (int j = 2; j <= b; j++) {
			while (1) {
				if (b % j == 0) {
					arrB[countB] = j;
					countB++;
					b /= j;
				}
				else {
					break;
				}
			}
		} // B의 약수

		for (int j = 0; j < countA; j++) {
			for (int k = 0; k < countB; k++) {
				if (arrA[j] == arrB[k]) {
					arrB[k] = -1;
					break;
				}
			}
		} // 중복 약수가 있으면 1개는 -1로 바꾸기

		int total = 1;
		for (int j = 0; j < countA; j++) {
			total *= arrA[j];
		}
		for (int j = 0; j < countB; j++) {
			if (arrB[j] != -1) {
				total *= arrB[j];
			}
		} // -1이 아닌거 빼고 전부 다 곱하기

		printf("%d\n", total);
	}
	return 0;
}