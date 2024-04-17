#include <stdio.h>
#include <math.h>
int main() {
	int n;
	scanf("%d", &n);

	int i = 2;
	while (i <= n) {
		int tf = 1;

		if (n % i == 0) {
			printf("%d\n", i);
			n /= i;
			tf = 0;
		}

		if (tf) {
			i++;
		}
	} // 2부터 나누어 떨어지면 출력
	// 안 나누어 떨어지면 i++

	return 0;
}