
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, x;

	scanf("%d", &n);
	scanf("%d", &x);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			printf("%d ", arr[i]);
		}
	}
	free(arr);

	return 0;
}