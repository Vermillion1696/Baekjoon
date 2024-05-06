#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int needString;
	int packageNum;
	scanf("%d %d", &needString, &packageNum);

	int arr[50][2];
	for (int i = 0; i < packageNum; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	} // 세트, 낱개 가격을 저장할 배열

	int setMin = 1001;
	int oneMin = 1001;
	for (int i = 0; i < packageNum; i++) {
		if (setMin > arr[i][0]) {
			setMin = arr[i][0];
		}
		if (oneMin > arr[i][1]) {
			oneMin = arr[i][1];
		}
	} // 세트, 낱개의 최소가를 찾음

	int total1 = 0;
	int total2 = 0;
	int total3 = 0;

	total1 += setMin * ((needString / 6) + 1);
	total2 += oneMin * needString;
	
	if (needString / 6 > 0) {
		total3 += setMin * (needString / 6);
		needString %= 6;
	}
	total3 += oneMin * needString;

	// 몫+1개만큼의 세트 사는 가격 vs 세트 + 낱개로 딱 맞게 사는 가격 vs 낱개만 사는 가격 비교

	if (total1 <= total2 && total1 <= total3) {
		printf("%d", total1);
	}
	else if (total2 <= total1 && total2 <= total3) {
		printf("%d", total2);
	}
	else {
		printf("%d", total3);
	}

	return 0;
}