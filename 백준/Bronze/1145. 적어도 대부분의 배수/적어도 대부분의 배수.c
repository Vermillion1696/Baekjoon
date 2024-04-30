#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int LCM(int a, int b) {
	int arr1[50];
	int arr2[50];
	int LCM = 1;
	// 최소 공배수 초기값 1

	int count1 = 0;
	for (int i = 2; i <= a; i++) {
		while (a % i == 0) {
			arr1[count1] = i;
			a /= i;
			count1++;
		}
	}
	int count2 = 0;
	for (int i = 2; i <= b; i++) {
		while (b % i == 0) {
			arr2[count2] = i;
			b /= i;
			count2++;
		}
	} // arr1, arr2에 각 숫자 소인수 분해 적기

	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (arr1[i] == arr2[j]) {
				arr2[j] = -1;
				break;
			}
		}
	} // 같은 수가 있으면 arr2에 -1 처리

	for (int i = 0; i < count1; i++) {
		LCM *= arr1[i];
	}
	for (int i = 0; i < count2; i++) {
		if (arr2[i] != -1) {
			LCM *= arr2[i];
		}
	} // arr2에 -1 처리 된 수 빼고 전부 곱하기

	return LCM;
}
int threeLCM(int a, int b, int c) {
	int temp = LCM(a, b);
	temp = LCM(temp, c);
	return temp;
} // 3개의 숫자 LCM은 2개 먼저 LCM 하고 나머지 하나랑 LCM

int main() {
	int arr[5];
	int combination[10];

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	int direction = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (i < j && j < k) {
					combination[direction] = threeLCM(arr[i], arr[j], arr[k]);
					direction++;
				}
			}
		}
	} // 5C3 구현

	int min;
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			min = combination[i];
		}
		else {
			if (min > combination[i]) {
				min = combination[i];
			}
		}
	} // 최소값 출력

	printf("%d", min);
	return 0;
}