#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	long long int total = 0;
	int n;
	scanf("%s", &n);

	char str[51];
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		total += (str[i] - 96) * pow(31, i);
	} // 총 값 += (ASCII (int)str - 96) -> a = 1, b = 2, ... * 31^i

	printf("%lld", total);
	return 0;
}