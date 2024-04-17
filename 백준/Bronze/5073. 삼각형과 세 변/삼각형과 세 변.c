#include <stdio.h>
int main() {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == b && b == c && c == 0) {
			break;
		} // 0 0 0 이면 탈출

		for (int i = 0; i < 3; i++) {
			if (a < b) {
				int temp = b;
				b = a;
				a = temp;
			}

			if (a < c) {
				int temp = c;
				c = a;
				a = temp;
			}

			if (b < c) {
				int temp = c;
				c = b;
				b = temp;
			}
		} // 큰 숫자부터 나오게 정렬

		if (a >= b + c) {
			printf("Invalid\n");
		}
		else if (a == b && b == c) {
			printf("Equilateral\n");
		}
		else if (a == b || b == c || c == a) {
			printf("Isosceles\n");
		}
		else {
			printf("Scalene\n");
		}
	}

	return 0;
}