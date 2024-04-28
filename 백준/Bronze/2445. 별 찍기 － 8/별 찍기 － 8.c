#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = n; j >= n - i; j--) {
			printf("*");
		}
		for (int j = 2 * (n - 1); j >= 2 * i + 1; j--) {
			printf(" ");
		}
		for (int j = n; j >= n - i; j--) {
			printf("*");
		}
		printf("\n");
	} // 상단

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			printf("*");
		}
		for (int j = 2; j <= 2 * (i + 1) + 1; j++) {
			printf(" ");
		}
		for (int j = n - 1; j > i; j--) {
			printf("*");
		}
		printf("\n");
	} // 하단

	return 0;
}