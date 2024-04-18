#include <stdio.h>

int divide(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return i;
		}
	}
	return n;
} // 약수 반환 함수

int main() {
	int num1Arr[1000];
	int num2Arr[1000];
	int allArr[2000];

	int times;
	scanf("%d", &times);

	for (int i = 0; i < times; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);

		int count1 = 0;
		while (1) {
			if (divide(num1) == num1) {
				num1Arr[count1] = num1;
				break;
			}
			num1Arr[count1] = divide(num1);
			num1 /= divide(num1);
			count1++;
		}

		int count2 = 0;
		while (1) {
			if (divide(num2) == num2) {
				num2Arr[count2] = num2;
				break;
			}
			num2Arr[count2] = divide(num2);
			num2 /= divide(num2);
			count2++;
		} // num1과 num2를 소인수분해 후 numArr에 저장

		for (int i = 0; i <= count1; i++) {
			for (int j = 0; j <= count2; j++) {
				if (num1Arr[i] == num2Arr[j]) {
					num2Arr[j] = -1;
					break;
				}
			}
		} // 중복수를 -1로 세팅

		unsigned long long int total = 1;
		for (int i = 0; i <= count1; i++) {
			total *= num1Arr[i];
		}
		for (int i = 0; i <= count2; i++) {
			if (num2Arr[i] != -1) {
				total *= num2Arr[i];
			}
		} // num1Arr은 모든 원소 곱하기, num2Arr은 -1이 아닌 것만 곱하기
		
		printf("%llu\n", total);
	}

	return 0;
}