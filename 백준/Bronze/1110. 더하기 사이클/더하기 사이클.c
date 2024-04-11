#include <stdio.h>
int main() {
	int original;
	scanf("%d", &original);

	int arr1[2];
	int arr2[2];
	arr1[0] = original / 10;
	arr1[1] = original % 10;

	int times = 0;
	while(1) {
		int temp = arr1[0] + arr1[1];
		arr2[0] = arr1[1];
		arr2[1] = temp % 10;
		times++;
		
		if (original == arr2[0] * 10 + arr2[1]) {
			break;
		}
		arr1[0] = arr2[0];
		arr1[1] = arr2[1];
	}
	printf("%d", times);
	return 0;
}