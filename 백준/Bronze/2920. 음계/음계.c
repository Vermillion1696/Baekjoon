#include<stdio.h>
int main() {
	int arr[8];
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}

	int temp = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i] == arr[i + 1] - 1) {
			temp++;
		}
		else if (arr[i] == arr[i + 1] + 1) {
			temp--;
		}
	}

	if (temp == 7) {
		printf("ascending");
	}
	else if (temp == -7) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
	return 0;
}