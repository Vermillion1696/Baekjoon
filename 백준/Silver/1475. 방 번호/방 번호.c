#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	} // 각 숫자가 나온 횟수를 저장할 배열

	int count = 0;
	while (n / 10 != 0) {
		int temp = n % 10;
		for (int i = 0; i < 10; i++) {
			if (temp == i) {
				arr[i]++;
			}
		}
		n /= 10;
		count++;
	} // modulo 연산자를 이용해 각 숫자의 횟수 카운트
	arr[n]++;
	count++;
	// 마지막 남은 n도 카운트

	int maxExcept69 = 0;
	int max69 = 0;
	int max6 = 0;
	int max9 = 0;

	for (int i = 0; i < 10; i++) {
		if (maxExcept69 < arr[i] && i != 6 && i != 9) {
			maxExcept69 = arr[i];
		}
		if (max6 < arr[i] && (i == 6)) {
			max6 = arr[i];
		}
		if (max9 < arr[i] && (i == 9)) {
			max9 = arr[i];
		}
	} // 6, 9가 나온 개수 & 6, 9 제외 나머지가 나온 개수

	max69 = max6 + max9;

	if (max69 % 2 == 0) {
		max69 /= 2;
	}
	else {
		max69 = (max69 / 2) + 1;
	} // 6, 9는 1세트에 2개씩이므로

	if (max69 > maxExcept69) {
		printf("%d", max69);
	}
	else {
		printf("%d", maxExcept69);
	} // 둘 중 더 큰걸 답으로 반환

	return 0;
}