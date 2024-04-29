#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int m, n, b;
	scanf("%d %d %d", &m, &n, &b);
	// 배열의 크기 n x m, 초기 블럭 개수 b

	int arr[500][500];
	// 배열의 최대 크기 선언

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	} // 배열에 각 좌표 블럭의 높이 입력

	int min, max;
	int totalTime = 0;
	while (1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) {
					min = arr[i][j];
					max = arr[i][j];
				}
				else {
					if (min > arr[i][j]) {
						min = arr[i][j];
					}
					if (max < arr[i][j]) {
						max = arr[i][j];
					}
				}
			}
		} // 최대, 최소 높이 구하기

		if (min == max) {
			break;
		} // 최대 == 최소이면 모든 arr[i][j]의 높이가 동일

		int needBlock = 0;
		int timeCheckCase1 = 0;
		int timeCheckCase2 = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == min) {
					timeCheckCase1++;
					needBlock++;
				}
				else if (arr[i][j] == max) {
					timeCheckCase2 += 2;
				}
			}
		} // arr[i][j]가 min인 곳에 블럭 설치 하는 시간 vs arr[i][j]가 max인 곳에 블럭 캐는 시간 비교
		// needBlock은 필요한 블럭 개수를 셈

		if (needBlock <= b && timeCheckCase1 <= timeCheckCase2) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == min) {
						arr[i][j]++;
						totalTime++;
						b--;
					}
				}
			}
			min++;
		} // 블럭의 개수가 충분하고 arr[i][j]가 min인 곳에 블럭을 설치 하는 시간이 더 짧으면 우선 적용 (답이 여러개라면 높이가 높은게 출력이 되어야 하므로)
		else {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == max) {
						arr[i][j]--;
						totalTime += 2;
						b++;
					}
				}
			}
			max--;
		} // 아니면 arr[i][j]가 max인 곳의 높이를 1씩 줄임
	} // 이를 min == max 일 때까지 반복

	printf("%d %d", totalTime, min);
	return 0;
}