#include <stdio.h>
int main() {
	long long int a, b, v;
	scanf("%lld %lld %lld", &a, &b, &v);
	long long int day = 1;
	day += (v - a) / (a - b);
	if ((v - a) % (a - b) != 0) {
		day++;
	}
	printf("%lld", day);
	return 0;
}