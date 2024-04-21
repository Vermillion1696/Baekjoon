#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	char str[50][51];
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	int changeCount = 0;
	while (1) {
		
		int tf1 = 0;
		int count1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 'X') {
					count1++;
					break;
				}
			}
		}
		if (count1 == n) {
			tf1 = 1;
		} // 행 체크

		int tf2 = 0;
		int count2 = 0;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (str[i][j] == 'X') {
					count2++;
					break;
				}
			}
		}
		if (count2 == m) {
			tf2 = 1;
		} // 열 체크

		if (tf1 == 1 && tf2 == 1) {
			break;
		} // 모든 행 열에 X가 (적어도) 한 개씩 있으면 통과

		else {
			int arr[50][50];
			// 각 좌표당 있는 점의 개수

			for (int x = 0; x < m; x++) {
				for (int y = 0; y < n; y++) {
					int dotCount = 0;

					for (int i = 0; i < n; i++) {
						if (str[i][x] == '.') {
							dotCount++;
						}
					}
					for (int i = 0; i < m; i++) {
						if (str[y][i] == '.') {
							dotCount++;
						}
					}
					if (str[y][x] == '.') {
						dotCount--;
					} // 겹치는 점 -1

					arr[y][x] = dotCount;
				}
			} // arr에 점의 개수 저장

			int max = 0;
			int maxX = 0;
			int maxY = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (max < arr[i][j] && str[i][j] != 'X') {
						max = arr[i][j];
						maxX = j;
						maxY = i;
					}
				}
			} // 점의 개수가 가장 많은 곳에 . -> X

			changeCount++;
			str[maxY][maxX] = 'X';
			// 변경 수 체크
		}
	}

	printf("%d", changeCount);
	return 0;
}
