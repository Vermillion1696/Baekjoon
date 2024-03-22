#include <stdio.h>
int main(){
	int a = 1;
	int b = 1;
	int sum = a + b;
	int times = 0;
	int x;
	scanf("%d", &x);

	for (int i = 0; i < 10000000; i++) {
		for (int j = 1; j < sum; j++) {
			if (sum % 2 == 1) {
				a = j;
				b = sum - j;
				times++;
				if (times == x) {
					break;
				}
			}
			else if (sum % 2 == 0) {
				a = sum - j;
				b = j;
				times++;
				if (times == x) {
					break;
				}
			}
		}
		if (times == x) {
			break;
		}
		sum++;
	}
	printf("%d/%d", a,b);
	return 0;
}