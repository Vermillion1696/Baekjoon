#include <stdio.h>
int main() {
	int times;
	scanf("%d", &times);

	int field[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			field[i][j] = 0;
		}
	} // 모든 필드의 원소를 0 (false)로 만듦

	for (int i = 0; i < times; i++) {
		int startX, startY;
		scanf("%d %d", &startX, &startY);
		for (int j = startX; j < startX + 10; j++) {
			for (int k = startY; k < startY + 10; k++) {
				field[j][k] = 1;
			}
		}
	} // times회동안 10x10 크기의 색종이에 해당하는 영역의 값을 1로 변경

	int total = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (field[i][j] == 1) {
				total++;
			}
		}
	} // 배열된 값이 1인 요소 세기

	printf("%d", total);
	return 0;
}