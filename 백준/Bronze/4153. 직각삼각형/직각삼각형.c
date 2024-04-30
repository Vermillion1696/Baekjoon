#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int temp;
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (a < c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (b < c) {
			temp = b;
			b = c;
			c = temp;
		}

		if (a == b && b == c && c == 0) {
			break;
		}
		else {
			if (a * a == b * b + c * c) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
	}

	return 0;
}