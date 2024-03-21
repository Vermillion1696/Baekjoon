#include <stdio.h>
int main(){
	long long int a, b;
	scanf("%lld", &a);
	scanf("%lld", &b);
	long long int total;
	long long int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	total = a - b;

	printf("%lld", total);
	return 0;
}