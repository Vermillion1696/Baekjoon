#include<stdio.h>

int main() {
	int arr[6];
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 6; i++) {
		if (0 <= i && i <= 1) {
			arr[i] = -arr[i] + 1;
		}
		else if (2 <= i && i <= 4) {
			arr[i] = -arr[i] + 2;
		}
		else if (i == 5) {
			arr[i] = -arr[i] + 8;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
}