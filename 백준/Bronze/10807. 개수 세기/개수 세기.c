
#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int arr[100];
	int times = 0;
	int whichone;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		scanf("%d", &temp);
		arr[i] = temp;
	}

	scanf("%d", &whichone);
	for (int i = 0; i < n; i++) {
		if (arr[i] == whichone) {
			times++;
		}
	}

	printf("%d",times);
}