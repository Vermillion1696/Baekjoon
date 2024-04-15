#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	char names[150][31];

	for (int i = 0; i < n; i++) {
		scanf("%s", names[i]);
	}

	int alphabet[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if ((int)names[i][0] == j + 97) {
				alphabet[j]++;
			}
		}
	}

	int tf = 1;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) {
			printf("%c", i + 97);
			tf = 0;
		}
	}

	if (tf == 1) {
		printf("PREDAJA");
	}

	return 0;
}