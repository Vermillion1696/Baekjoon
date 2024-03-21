#include <stdio.h>
int main(){
	int a;
	int t = 1;
	scanf("%d", &a);
	for (int i = a; i > 0; i--) {
		t *= i;
	}
	printf("%d", t);
}