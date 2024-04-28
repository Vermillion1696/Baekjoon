#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);

	int temp;

	if (a1 > a2) {
		temp = a1;
		a1 = a2;
		a2 = temp;
	}

	if (a1 > a3) {
		temp = a1;
		a1 = a3;
		a3 = temp;
	}

	if (a2 > a3) {
		temp = a2;
		a2 = a3;
		a3 = temp;
	}

	printf("%d %d %d", a1, a2, a3);

	return 0;
}