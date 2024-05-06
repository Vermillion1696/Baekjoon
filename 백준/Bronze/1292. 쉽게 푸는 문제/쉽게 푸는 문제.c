#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int arr[1000];

	int count = 1;
	int target = 1;
	for (int i = 0; i < 1000; i++) {

		if (count < target) {
			arr[i] = target;
			count++;
		}
		else {
			arr[i] = target;
			count = 1;
			target++;
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	long long int total = 0;
	for (int i = a - 1; i < b; i++) {
		total += arr[i];
	}

	printf("%lld", total);
	return 0;
}