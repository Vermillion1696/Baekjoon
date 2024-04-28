#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int arr[7];

	int temp;
	int count = 0;
	for (int i = 0; i < 7; i++) {
		scanf("%d", &temp);
		
		if (temp % 2 == 1) {
			arr[count] = temp;
			count++;
		}
	}

	int sum = 0;
	int min;

	if (count != 0) {
		for (int i = 0; i < count; i++) {
			if (i == 0) {
				min = arr[i];
			}
			else {
				if (min > arr[i]) {
					min = arr[i];
				}
			}

			sum += arr[i];
		}

		printf("%d\n%d", sum, min);
	}
	else {
		printf("-1");
	}

	return 0;
}