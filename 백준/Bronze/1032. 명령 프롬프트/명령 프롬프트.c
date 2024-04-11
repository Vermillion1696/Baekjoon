#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	char str[50][51];
	// 가로 51 (NULL 포함), 세로 50

	for (int times = 0; times < n; times++) {
		scanf("%s", str[times]);
	}

	for (int length = 0; length < strlen(str[0]); length++) {
		int tf = 1;
		for (int times = 0; times < n - 1; times++) {
			if (str[times][length] != str[times + 1][length]) {
				tf = 0;
				break;
			}
		}
		if (tf == 1) {
			printf("%c", str[0][length]);
		}
		else {
			printf("?");
		}
	}
	return 0;
}