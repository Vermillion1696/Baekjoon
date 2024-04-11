#include <stdio.h>
int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int min1, min2;

	min1 = x < y ? x : y;
	min2 = (w - x) < (h - y) ? w - x : h - y;
	min1 = min1 < min2 ? min1 : min2;

	printf("%d", min1);
	return 0;
}