#include <stdio.h>
int main() {
	int min1, min2, max1, max2;
	int n;
	scanf("%d", &n);

	min1 = 10001;
	min2 = 10001;
	max1 = -10001;
	max2 = -10001;
	// -10,000~10,000이므로 이거보다 더 넓은 숫자로 초기화

	for (int i = 0; i < n; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		if (temp1 > max1) {
			max1 = temp1;
		}
		
		if (temp1 < min1) {
			min1 = temp1;
		}

		if (temp2 > max2) {
			max2 = temp2;
		}

		if (temp2 < min2) {
			min2 = temp2;
		}
	}
	// 좌표의 최대 최소 찾기

	if (n != 1) {
		printf("%d", (max1 - min1) * (max2 - min2));
	}
	else {
		printf("0");
	}
	// 넓이 출력

	return 0;
}