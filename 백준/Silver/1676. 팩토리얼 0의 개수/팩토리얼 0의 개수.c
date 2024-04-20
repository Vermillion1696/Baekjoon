#include <stdio.h>
#include <stdlib.h>
int main() {
	int five = 0;
	int two = 0;

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int temp = i;
		while (1) {
			if (temp % 5 == 0) {
				five++;
				temp /= 5;
			}
			if (temp % 2 == 0) {
				two++;
				temp /= 2;
			}
			if (temp % 2 != 0 && temp % 5 != 0) {
				break;
			} // 2와 5의 개수 카운트
		}
	}

	if (five <= two) {
		printf("%d", five);
	}
	else {
		printf("%d", two);
	} // 2와 5중 더 적은게 10의 개수

	return 0;
}