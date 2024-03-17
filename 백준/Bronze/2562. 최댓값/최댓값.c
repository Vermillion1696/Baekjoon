
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[9];
	
	for (int i = 0; i < 9; i++) {
		arr[i] = 0;
	} // 배열 초기화, 100보다 작은 자연수를 받으므로 0으로 초기화

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	int max = arr[0];
	int whichline;

	for (int i = 0; i < 9; i++) {
		if (max <= arr[i]) {
			max = arr[i];
			whichline = i + 1;
		}
	}
	
	printf("%d\n%d", max, whichline);

	return 0;
}