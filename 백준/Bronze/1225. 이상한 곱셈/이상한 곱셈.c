#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str1[10101];
	char str2[10101];
	scanf("%s", str1);
	scanf("%s", str2);

	long long int sum = 0;
	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			sum += (str1[i] - 48) * (str2[j] - 48);
		}
	}

	printf("%lld", sum);
	return 0;
}