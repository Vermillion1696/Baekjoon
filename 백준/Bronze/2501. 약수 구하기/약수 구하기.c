#include <stdio.h>
int main() {
	int n, k;
	int arr[10000];
	scanf("%d %d", &n, &k);
	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[count] = i;
			count++;
		}
	} // arr 배열에 n의 약수 순서대로 저장

	if (count < k) {
		printf("0");
	}
	else {
		printf("%d", arr[k - 1]);
	} // k가 약수의 개수(count)보다 크면 0, 아니면 이에 맞는 수 출력

	return 0;
}