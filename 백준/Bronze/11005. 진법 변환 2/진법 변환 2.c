#include <stdio.h>
#include <stdlib.h>

int pow(int a, int b) {
	int total = 1;
	if (a == 0) {
		return total;
	}
	for (int i = 0; i < b; i++) {
		total *= a;
	}
	return total;
} // 제곱 함수

int main() {
	int n, b;
	scanf("%d %d",&n,&b);
	// n, b 입력
	
	int length = 0;
	int temp = n;
	for (int i = 0; i < 99; i++) {
		n /= b;
		length++;
		if (n == 0) {
			break;
		}
	} // 몇 개의 칸이 필요한지 체크

	int arr[30];
	for (int i = 0; i < 30; i++) {
		arr[i] = -1;
	} // 배열 -1로 초기화

	n = temp;
	for (int i = 0; i < length; i++) {
		arr[i] = n / pow(b, i);
	}
	for (int i = 0; i < length; i++) {
		arr[i] %= b;
	} // 각 진수에 해당하는 나머지를 배열에 넣음

	
	for (int i = 0; length - i >= 0; i++) {
		if (arr[length - i] >= 0 && arr[length - i] <= 9) {
			printf("%d", arr[length - i]);
		}
		else if (arr[length - i] >= 10 && arr[length - i] <= 35) {
			printf("%c", arr[length - i] + 55);
		}
	} // 내림차순 -> 오름차순으로 변경 후 출력
	return 0;
}