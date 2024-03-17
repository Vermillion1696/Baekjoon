
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	int i = 0;
	int j = 0;

	for (int t = 0; t < m; t++) {
		scanf("%d %d", &i, &j);
		int temp = 0;
		temp = arr[i - 1];
		arr[i - 1] = arr[j - 1];
		arr[j - 1] = temp;
	}

	for (int k = 0; k < n; k++) {
		printf("%d ", arr[k]);
	}

	free(arr);

	return 0;
}