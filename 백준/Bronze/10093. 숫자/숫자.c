#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int a, b;
	scanf("%lld %lld", &a, &b);

	if (a > b)
	{
		long long int temp = a;
		a = b;
		b = temp;
	}

	if (b - a <= 1) {
		printf("0");
		return 0;
	}
	else {
		printf("%lld\n", b - a - 1);
	}

	a++;
	while (a < b) {
		printf("%lld ", a);
		a++;
	}

	return 0;
}