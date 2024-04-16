#include <stdio.h>
int mostSimilar(int arr[], int size, int num) {
	int temp = 0;
	int sumThree;
	for (int i = 0; i < size - 2; i++) {
		for (int j = 1; j < size - 1; j++) {
			for (int k = 2; k < size; k++) {
				if (i != j && j != k && k != i) {
					sumThree = arr[i] + arr[j] + arr[k];
					if (sumThree > temp && sumThree <= num) {
						temp = sumThree;

					}
				}
			}
		}
	}
	return temp;
}
// 3연 for문 -> nC3을 의미
// if (i != j && j != k && k != i) -> 다음으로 넘어갈 때 숫자 중복 카운트 경우 배제
// ex) arr[0]+arr[1]+arr[9] -> arr[0]+arr[2]+arr[2] 방지
// 3개의 합이 num보다 작거나 같고 temp(최대)보다 클때 저장

int main() {
	int card, num;
	scanf("%d %d", &card, &num);
	int arr[100];
	int length = 0;

	for (int i = 0; i < card; i++) {
		scanf("%d", &arr[i]);
		length++;
	}

	printf("%d", mostSimilar(arr, length, num));
	return 0;
}