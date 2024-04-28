#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int nineShort[9];
	int total = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &nineShort[i]);
		total += nineShort[i];
	} // 9명의 키를 입력 받음

	int direction[2];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (total - nineShort[i] - nineShort[j] == 100) {
				direction[0] = i;
				direction[1] = j;
			}
		}
	} // 합이 100이 되는 애들이 아닌 나머지 쁘락치 찾기

	int sevenShort[7];
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (i != direction[0] && i != direction[1]) {
			sevenShort[count] = nineShort[i];
			count++;
		}
	} // 7명 배열로 재구성

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6 - i; j++) {
			if (sevenShort[j] > sevenShort[j + 1]) {
				int temp = sevenShort[j];
				sevenShort[j] = sevenShort[j + 1];
				sevenShort[j + 1] = temp;
			}
		}
	} // 버블 정렬로 오름차순 정리

	for (int i = 0; i < 7; i++) {
		printf("%d\n", sevenShort[i]);
	}

	return 0;
}