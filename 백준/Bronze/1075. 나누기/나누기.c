#include <stdio.h>
int main() {
	int n, f;
	scanf("%d %d", &n, &f);

	if (n >= 100) {
		n -= (n % 100);
	} // 맨 뒤를 00으로 바꿈

	for (int times = 0; times < 100; times++) {
		if (n % f == 0) {
			f = n % 100;
			break;
		}
		else {
			n++;
		}
	} // 00부터 ++ 하면서 나누어 떨어질때까지 반복
	
	if (f < 10) {
		printf("0%d", f);
	}
	else {
		printf("%d", f);
	} // f < 10이면 0n으로 출력하기 위한 조건문

	return 0;
}