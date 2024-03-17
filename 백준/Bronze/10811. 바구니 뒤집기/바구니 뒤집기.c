#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void swapTwo(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void inverseResult(int arr[], int start, int end) {

	int times = (end - start + 1) / 2;
	
	for (int i = 0; i < times; i++) {
		swapTwo(&arr[start+i-1], &arr[end-i-1]);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		inverseResult(arr, p, q);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}