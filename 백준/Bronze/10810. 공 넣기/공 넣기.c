
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	for (int t = 0; t < m; t++) {
		int i = 0;
		int j = 0;
		int k = 0;
		scanf("%d %d %d", &i, &j, &k);
		
		while (i <= j) {
			arr[i-1] = k;
			i++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}