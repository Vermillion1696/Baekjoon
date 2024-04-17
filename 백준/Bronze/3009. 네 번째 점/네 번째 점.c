#include <stdio.h>
int main() {
	int arr[3][2];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	if (arr[0][0] == arr[1][0]) {
		printf("%d ", arr[2][0]);
	}
	else if (arr[1][0] == arr[2][0]) {
		printf("%d ", arr[0][0]);
	}
	else {
		printf("%d ", arr[1][0]);
	} //  가로

	if (arr[0][1] == arr[1][1]) {
		printf("%d", arr[2][1]);
	}
	else if (arr[1][1] == arr[2][1]) {
		printf("%d", arr[0][1]);
	}
	else {
		printf("%d", arr[1][1]);
	} //  세로

	return 0;
}