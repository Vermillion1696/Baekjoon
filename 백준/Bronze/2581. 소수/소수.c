#include <stdio.h>
int main() {
	int allPrime[2000];
	// 모든 소수를 저장할 배열

	allPrime[0] = 2;
	int length = 0;
	for (int i = 3; i < 10000; i += 2) {
		int tf = 1;
		for (int j = 0; j <= length; j++) {
			if (i % allPrime[j] == 0) {
				tf = 0;
				break;
			}
		}

		if (tf) {
			length++;
			allPrime[length] = i;
		}
	} // 3부터 2씩 증가시키면서 소수인지 아닌지 판별
	// allPrime[0] = 2, allPrime[1]부터 소수일때 저장
	
	int m, n;
	scanf("%d %d", &m, &n);


	int total = 0;
	int tf = 1;
	int count = 0;
	int min;
	for (int i = 0; i <= length; i++) {
		if (allPrime[i] >= m && allPrime[i] <= n) {
			total += allPrime[i];
			count++;
			if (tf) {
				min = allPrime[i];
				tf = 0;
			}
		}
	} // allPrime 원소중 m ~ n 사이의 수를 판별

	if (count != 0) {
		printf("%d %d", total, min);
	}
	else {
		printf("-1");
	} // 있으면 출력, 없으면 -1

	return 0;
}