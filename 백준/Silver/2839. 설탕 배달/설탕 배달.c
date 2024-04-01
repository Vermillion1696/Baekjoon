#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int howmany = 0;
	for (int i = 1; i < 5; i++) {
		if ((n - 3 * i) % 5 == 0 && n - 3 * i >= 0) {
			howmany += i;
			n -= 3 * i;
		}
	}
	howmany += n / 5;
	if (n % 5 != 0) {
		howmany = -1;
	}
	printf("%d", howmany);
	return 0;
}