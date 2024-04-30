#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int total = 1;
	for (int i = n; i > n - k; i--) {
		total *= i;
	}
	for (int i = k; i > 0; i--) {
		total /= i;
	}

	printf("%d", total);
	return 0;
}