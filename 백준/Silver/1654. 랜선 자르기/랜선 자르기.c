#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

	long long int n, k;
	scanf("%lld %lld", &n, &k);
	// max length가 2^31 - 1 이므로 long long int

	long long int arr[10000];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	} // 배열에 각 랜선의 길이 입력

	long long int last = 1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			last = arr[i];
		}
		else {
			if (last < arr[i]) {
				last = arr[i];
			}
		}
	} // 최댓값 구하기

	if (n == 1) {
		printf("%lld", arr[0] / k);
	}
	else {
		long long int first = 1;
		long long int mid;
		long long int max = 0;
		
		while (first <= last) {
			mid = (first + last) / 2;

			long long int quotient = 0;
			for (int i = 0; i < n; i++) {
				quotient += (arr[i] / mid);
			}

			if (quotient >= k) {
				if (max < mid) {
					max = mid;
				} // 나머지가 최대한 없게
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		// first > last인 상황이 되면 종료

		printf("%lld", max);
	} // 이진 탐색 알고리즘 적용 후 반환

	return 0;
}