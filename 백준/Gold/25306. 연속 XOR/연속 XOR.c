#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// point : a % 2 == 0 일때와 a % 2 == 1 일때의 4연 XOR 연산 규칙이 다름

long long int pow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	else {
		long long int total = 1;
		for (int i = 0; i < b; i++) {
			total *= a;
		}
		return total;
	}
} // pow를 long long int 형으로 반환

long long int XOR(long long int a, long long int b) {

	int arrA[60]; // a 2진수 변환 저장 배열
	int arrB[60]; // b 2진수 변환 저장 배열
	int arrTotal[60]; // XOR 연산 결과값 2진수 저장 배열
	long long int total = 0; // XOR 연산 결과값

	for (int i = 60; i > 0; i--) {
		arrA[60 - i] = a % 2;
		arrB[60 - i] = b % 2;
		a /= 2;
		b /= 2;
	}

	for (int i = 60; i > 0; i--) {
		if (arrA[60 - i] == arrB[60 - i]) {
			arrTotal[60 - i] = 0;
		}
		else {
			arrTotal[60 - i] = 1;
		}
	}

	for (int i = 0; i < 60; i++) {
		total += arrTotal[i] * pow(2, i);
	}

	return total;
} // XOR 연산 함수

int main() {

	long long int a, b, result;
	scanf("%lld %lld", &a, &b);
	long long int length = b - a;
	long long int count = 0;

	/*
	long long int tempA = a;
	long long int tempB = b;
	long long int tempResult = tempA;
	for (long long int i = tempA; i < tempB; i++) {
		tempResult = XOR(tempResult, i + 1);
		printf("%lld ~ %lld XOR -> %lld\n", tempA, i + 1, tempResult);
	}
	printf("\n%lld\n\n", tempResult);
	*/ // 실제로 연속 XOR을 하는 비교용 코드
	

	if (a % 2 == 0) {
		count = (b - a) % 4;
		result = b - count;

		if (count == 0) {
			printf("%lld", b);
		}
		else if (count == 1) {
			result = XOR(result, b);
			printf("%lld", result);
		}
		else if (count == 2) {
			result = XOR(result, b - 1);
			result = XOR(result, b);
			printf("%lld", result);
		}
		else {
			result = XOR(result, b - 2);
			result = XOR(result, b - 1);
			result = XOR(result, b);
			printf("%lld", result);
		}
	} // a % 2 == 0일때  b - a가 4의 배수인 b의 번호까지 XOR -> b

	else if (a % 2 == 1) {
		count = (b - a) % 4;
		result = a;

		if (count == 0) {
			printf("%lld", a);
		}
		else if (count == 1) {
			result = XOR(result, b);
			printf("%lld", result);
		}
		else if (count == 2) {
			result = XOR(result, b - 1);
			result = XOR(result, b);
			printf("%lld", result);
		}
		else {
			result = XOR(result, b - 2);
			result = XOR(result, b - 1);
			result = XOR(result, b);
			printf("%lld", result);
		} // a % 2 == 1일때  b - a가 4의 배수인 b의 번호까지 XOR -> a
	}

	return 0;
}