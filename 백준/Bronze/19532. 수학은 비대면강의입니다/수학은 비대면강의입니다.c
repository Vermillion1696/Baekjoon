#include <stdio.h>
int main() {
	int a, b, c, d, e, f, x, y;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int temp1, temp2, temp3, temp4, temp5, temp6;

	temp1 = a;
	temp2 = b;
	temp3 = c;
	temp4 = d;
	temp5 = e;
	temp6 = f;
	// 리셋

	temp1 *= d;
	temp2 *= d;
	temp3 *= d;
	temp4 *= a;
	temp5 *= a;
	temp6 *= a;
	y = (temp3 - temp6) / (temp2 - temp5);
	// y 구하기

	temp1 = a;
	temp2 = b;
	temp3 = c;
	temp4 = d;
	temp5 = e;
	temp6 = f;
	// 리셋

	temp1 *= e;
	temp2 *= e;
	temp3 *= e;
	temp4 *= b;
	temp5 *= b;
	temp6 *= b;
	x = (temp3 - temp6) / (temp1 - temp4);
	// x 구하기

	printf("%d %d", x, y);
	
	return 0;
}