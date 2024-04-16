#include <stdio.h>
int main() {
	int arr[9][9];

	int max = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	} // 2차원 배열에 모든 값 저장

	int tf = 1;
	printf("%d\n", max);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (max == arr[i][j]) {
				printf("%d %d", i + 1, j + 1);
				tf = 0;
				break;
			}
		}
		if (!tf) {
			break;
		}
	} // 각 배열의 원소를 검사해서 max와 동일하면 위치를 출력 후 break;
	return 0;
}