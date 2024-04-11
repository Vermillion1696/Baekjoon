#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	char str[10];

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		printf("%d\n", str[0] + str[2] - 96);
	}
	
	return 0;
}