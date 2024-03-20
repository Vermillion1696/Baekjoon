#include<stdio.h>
int main() {
	int number[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &number[i]);
	}
	// 5자리 입력받기

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		number[i] *= number[i];
	}
	for (int i = 0; i < 5; i++) {
		sum += number[i];
	}
	sum %= 10;
	printf("%d", sum);
	// 검증수 구하기

	return 0;
}