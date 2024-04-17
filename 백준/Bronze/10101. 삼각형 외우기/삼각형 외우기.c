#include <stdio.h>
int main() {
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a == b && b == c && c == 60) {
		printf("Equilateral");
	}
	else if (a + b + c == 180 && (a == b || b == c || c == a)) {
		printf("Isosceles");
	}
	else if (a + b + c == 180 && a != b && b != c && c != a) {
		printf("Scalene");
	}
	else {
		printf("Error");
	}

	return 0;
}