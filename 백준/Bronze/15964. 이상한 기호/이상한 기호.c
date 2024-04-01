#include <stdio.h>
int golbeng(int a, int b) {
	int total;
	total = (a + b) * (a - b);
	return total;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int temp;
	temp = golbeng(a, b);
	printf("%d", temp);
	return 0;
}