#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = n - i; j < n; j++) {
			printf(" ");
		}
		for (int j = 2 * n - 1; j > 2 * i; j--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}