#include <stdio.h>
#include <math.h>

int primeORnot(int a) {
	double t = sqrt(a);
	int tf = 1;
	for (int i = 2; i <= t; i++) {
		if (a % i == 0) {
			tf = 0;
		}
	}
	if (a == 1) {
		tf = 0;
	}
	return tf;
} // 소수 판별 함수, tf는 bool의 역할이며 루트 a보다 작은 수로 나누었을 때
// 나누어 떨어지면 합성수임

int main() {
	int n;
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = -1;
	}

	scanf("%d", &n);
	int times = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (primeORnot(arr[i]) == 1) {
			times++;
		}
	}
	printf("%d", times);
	return 0;
}