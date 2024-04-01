#include <stdio.h>
long long int golbeng(long long int a, long long int b) {
	long long int total;
	total = (a + b) * (a - b);
	return total;
}
int main() {
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	long long int temp;
	temp = golbeng(a, b);
	printf("%lld", temp);
	return 0;
}