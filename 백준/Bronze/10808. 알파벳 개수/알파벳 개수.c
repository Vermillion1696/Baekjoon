#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int alphabet[26];
	char str[101];

	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	scanf("%s", &str);

	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < 26; j++) {
			if ((int)str[i] == 97 + j) {
				alphabet[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}

	return 0;
}