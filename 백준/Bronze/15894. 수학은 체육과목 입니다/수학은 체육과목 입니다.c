#include <stdio.h>
int main() {
	long long int n;
	scanf("%lld", &n);

	long long int total = (n + 1) * 2 + (n - 1) * 2;
	printf("%lld", total);

	return 0;
}