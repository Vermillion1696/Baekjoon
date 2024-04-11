#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	int arr[50];

	long long int min, max; 
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			min = arr[i];
			max = arr[i];
		}
		else {
			if (min > arr[i]) {
				min = arr[i];
			}
			else if (max < arr[i]) {
				max = arr[i];
			}
		}
	}

	long long int total = min * max;
	printf("%lld", total);

	return 0;
}