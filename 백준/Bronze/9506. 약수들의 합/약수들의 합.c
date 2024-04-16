#include <stdio.h>
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == -1) {
			break;
		}

		int count = 0;
		int arr[200];
		// 1~100,000중 약수가 제일 많은 숫자의 약수 개수는 128 (사전검색)

		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				arr[count] = i;
				count++;
			}
		} // arr[]에 약수 순서대로 저장

		int sum = 0;
		for (int i = 0; i < count - 1; i++) {
			sum += arr[i];
		} // 각 약수의 합을 sum에 저장

		if (sum == n) {
			printf("%d = ", n);
			for (int i = 0; i < count - 1; i++) {
				if (i < count - 2) {
					printf("%d + ", arr[i]);
				}
				else {
					printf("%d", arr[i]);
				}
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", n);
		} // sum = n이면 각 약수의 합 = n 출력, 아니면 is not perfect 출력
	}

	return 0;
}