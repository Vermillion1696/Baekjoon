#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int h, w, n, m;
	scanf("%d %d %d %d", &h, &w, &n, &m);


	int maxHeight;
	int maxWidth;
	if (h % (n + 1) != 0) {
		maxHeight = (h / (n + 1)) + 1;
	}
	else {
		maxHeight = h / (n + 1);
	}
	if (w % (m + 1) != 0) {
		maxWidth = (w / (m + 1)) + 1;
	}
	else {
		maxWidth = w / (m + 1);
	}
	int max = maxHeight * maxWidth;

	printf("%d", max);
	return 0;
}