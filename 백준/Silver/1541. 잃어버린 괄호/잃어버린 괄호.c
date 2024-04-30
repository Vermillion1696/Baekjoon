#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int tempSum = 0;
	int totalSum = 0;
	int counter = 0;
	char str[51];
	scanf("%s", str);

	for (int i = strlen(str); i >= 0; i--) {
		if ((int)str[i] >= 48 && (int)str[i] <= 57) {
			tempSum += pow(10, counter) * (str[i] - 48);
			counter++;
		} // 숫자면 자릿수에 맞는 숫자를 (10^counter)*숫자를 tempSum에 더함
		else if (str[i] == '+') {
			counter = 0;
		} // +를 만나면 자릿수 초기화 
		else if (str[i] == '-') {
			counter = 0;
			totalSum += tempSum;
			tempSum = 0;
		} // -를 만나면 자릿수 초기화, totalSum에 더하고 tempSum 초기화
	}

	totalSum *= (-1);
	totalSum += tempSum;
	// 이전까지의 tempSum은 어차피 괄호로 묶으면 -가 있을때 전부 음수 처리 가능
	// 마지막 tempSum은 양수로 들어가므로...

	printf("%d", totalSum);
	return 0;
}