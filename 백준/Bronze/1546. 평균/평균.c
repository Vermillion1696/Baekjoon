
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* arr1 = (int*)malloc(n * sizeof(int));
	int max = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
		if (max < arr1[i]) {
			max = arr1[i];
		}
	}

	double* arr2 = (double*)malloc(n * sizeof(double));
	double sum = 0.0;
	double average = 0.0;

	for (int i = 0; i < n; i++) {
		arr2[i] = ((double)arr1[i] / max) * 100;
		sum += arr2[i];
	}
	
	average = sum / n;
	printf("%lf", average);

	free(arr1);
	free(arr2);

	return 0;
}