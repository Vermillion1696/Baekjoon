#include <stdio.h>
int main() {
	int s1, s2, s3;
	scanf("%d %d %d", &s1, &s2, &s3);
	// 3개의 면 수 받기

	int arr[80];
	for (int i = 0; i < 80; i++) {
		arr[i] = 0;
	} // 0으로 초기화

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				int temp = i + j + k;
				arr[temp - 1]++;
			}
		}
	} // s1 + s2 + s3 의 max 80까지 각각 몇 번 나오는지 체크

	int max = 0;
	int index = 0;
	for (int i = 0; i < 80; i++) {
		if (max < arr[i]) {
			max = arr[i];
			index = i + 1;
		}
	} // max의 index 구하기

	printf("%d", index);
	return 0;
}