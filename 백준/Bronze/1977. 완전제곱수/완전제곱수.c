#include <stdio.h>
#include <math.h>
int main() {
	int arr[100];
	for (int i = 1; i <= 100; i++) {
		arr[i - 1] = pow(i, 2);
	} // 100칸의 int 배열에 10000까지의 완전제곱수 할당

	int m, n;
	scanf("%d %d", &m, &n);
	int total = 0;
	int least;
	int tf = 1;
	for (int i = 1; i <= 100; i++) {
		if (arr[i - 1] >= m && arr[i - 1] <= n) {
			total += arr[i - 1];
			if (tf == 1) {
				tf = 0;
				least = arr[i - 1];
			}
		}
	} // 두 수 사이에 있는 완전제곱수를 저장

	if (total != 0) {
		printf("%d %d", total, least);
	}
	else {
		printf("-1");
	}

	return 0;
}