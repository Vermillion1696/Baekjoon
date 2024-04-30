#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr1[1000];
	int arr2[1000];
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	// 배열 선언

	int GCF = 1; // 최대공약수
	int LCM = 1; // 최소공배수

	int count1 = 0;
	int count2 = 0;
	for (int i = 2; i <= num1; i++) {
		if (num1 % i == 0) {
			arr1[count1] = i;
			count1++;
		}
	}
	for (int i = 2; i <= num2; i++) {
		if (num2 % i == 0) {
			arr2[count2] = i;
			count2++;
		}
	}
	// 각 수의 약수를 arr1, arr2에 저장

	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (arr1[i] == arr2[j]) {
				GCF = arr1[i];
				arr2[j] = -1;
				break;
			}
		}
	}
	// 공통된게 있으면 GCF에 곱하고 arr2에 있는걸 -1로 치환 (중복방지)
	// 여기까지 GCF

	count1 = 0;
	count2 = 0;
	for (int i = 2; i <= num1; i++) {
		while (num1 % i == 0) {
			arr1[count1] = i;
			num1 /= i;
			count1++;
		}
	}

	for (int i = 2; i <= num2; i++) {
		while (num2 % i == 0) {
			arr2[count2] = i;
			num2 /= i;
			count2++;
		}
	} // 각 수를 소인수분해 한 값을 배열에 저장

	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (arr1[i] == arr2[j]) {
				arr2[j] = -1;
				break;
			}
		}
	} // 중복이 있다면 arr2의 값을 -1 치환

	for (int i = 0; i < count1; i++) {
		LCM *= arr1[i];
	}
	for (int i = 0; i < count2; i++) {
		if (arr2[i] != -1) {
			LCM *= arr2[i];
		}
	} // 중복을 제외한 모든 값 곱하기

	printf("%d\n%d", GCF, LCM);
	return 0;
}