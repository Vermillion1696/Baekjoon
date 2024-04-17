#include <stdio.h>
int main() {
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 0; i < 3; i++) {
		if (a < b) {
			int temp = b;
			b = a;
			a = temp;
		}
		if (a < c) {
			int temp = c;
			c = a;
			a = temp;
		}
		if (b < c) {
			int temp = c;
			c = b;
			b = temp;
		}
	} // 큰 숫자부터 나오게 정렬

	if (a >= b + c) {
		a = b + c - 1;
	} // 삼각형 조건 충족 불가면 제일 큰 숫자 변경

	printf("%d", a + b + c);
	// 둘레 출력

	return 0;
}