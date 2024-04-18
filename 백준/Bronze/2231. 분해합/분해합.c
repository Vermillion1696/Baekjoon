#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int tf = 0;
	int result;
	for (int i = 1; i <= n; i++) {
		
		int leftoverSum = 0;
		int tempI = i;
		for (int j = 0; j < 7; j++) {
			leftoverSum += (tempI % 10);
			tempI /= 10;
		} // 각 자리 수의 합 (i)

		if (i + leftoverSum == n) {
			tf = 1;
			result = i;
			break;
		} // i + 각 자리 수의 합이 원 수 n과 같으면 참으로 바꾸고 break
	}

	if (tf == 0) {
		printf("0");
	}
	else if (tf == 1) {
		printf("%d", result);
	}
	
	return 0;
}