/*
설명 : n이 증가하기 직전 마지막 방 번호 : 0, 6, 18, 36, 60 ...
방 번호 / 6 : 0, 1, 3, 6, 10 ...
<< 상단의 수열의 증가 폭이 1 2 3 4임을 확인 가능
하단에 구현
*/
#include <stdio.h>
int main() {
	long long int n;
	scanf("%lld", &n);
	long long int num = 0;
	long long int numdiv6 = 0;
	while (6 * num < n - 1) {
		numdiv6++;
		num += numdiv6;
	}
	if (n == 1) {
		printf("%d", 1);
	}
	else if (n != 1) {
		printf("%lld", numdiv6 + 1);
	}
	return 0;
}