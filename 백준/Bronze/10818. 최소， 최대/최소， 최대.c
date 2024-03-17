
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int min = 1000000;
	int max = -1000000;

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	printf("%d %d", min, max);

	return 0;
}