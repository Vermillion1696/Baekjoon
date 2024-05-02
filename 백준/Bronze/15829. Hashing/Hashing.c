#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long int total = 0;
	int n;
	scanf("%d", &n);

	char str[51];
	scanf("%s", str);

	for (int i = 0; i < n; i++) {
		long long int m = 1;
		for (int j = 0; j < i; j++) {
			m *= 31;
			m %= 1234567891;
		}
		total += ((str[i] - 96) * m) % 1234567891;
		total %= 1234567891;
	} // 총 값 += (ASCII (int)str - 96) -> a = 1, b = 2, ... * 31^i
	// 에다가 mod 1234567891

	printf("%lld", total % 1234567891);
	return 0;
}