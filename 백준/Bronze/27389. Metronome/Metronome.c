#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double num;
	scanf("%lf", &num);

	printf("%.2lf", num / 4);
	return 0;
}