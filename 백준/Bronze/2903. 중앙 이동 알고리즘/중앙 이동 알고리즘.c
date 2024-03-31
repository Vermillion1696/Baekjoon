#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	// 개수 받기

	int length = 2;
	for (int i = 0; i < n; i++) {
		length = 2 * length - 1;
	} // 한 변에 점이 몇 개인지 구하기

	length *= length;
	printf("%d", length);
	// 제곱

	return 0;
}