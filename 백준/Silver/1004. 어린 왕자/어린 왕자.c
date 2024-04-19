#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int distanceChecker(int startX, int startY, int endX, int endY, int x, int y, int r) {
	int times = 0;
	int distanceStart = abs((startX - x)) * abs((startX - x)) + abs((startY - y)) * abs((startY - y));
	int distanceEnd = abs((endX - x)) * abs((endX - x)) + abs((endY - y)) * abs((endY - y));
	// 시작점과의 거리, 끝점과의 거리  (제곱)

	if (distanceStart <= r * r && distanceEnd > r * r) {
		times++;
	}
	if (distanceEnd <= r * r && distanceStart > r * r) {
		times++;
	} // distanceStart, distanceEnd 둘 중 하나만 <= r^2 이면 경계를 지남
	// distanceStart <= r^2 && distanceEnd <= r^2이면 행성계 안에 시작점과 출발점이 둘 다 있는 것 (경계 안 지남)

	return times;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	// 테스트 케이스

	int arr[50][3];
	// 행성계의 x, y, r을 저장할 배열 (최대 50개)

	for (int i = 0; i < testCase; i++) {

		int startX, startY, endX, endY;
		scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
		// 좌표

		int times;
		scanf("%d", &times);
		// 행성계의 개수

		for (int j = 0; j < times; j++) {
			for (int k = 0; k < 3; k++) {
				scanf("%d", &arr[j][k]);
			}
		} // 배열에 값 저장

		int count = 0;
		for (int j = 0; j < times; j++) {
			count += distanceChecker(startX, startY, endX, endY, arr[j][0], arr[j][1], arr[j][2]);
		} // 모든 arr 요소에 대해 distanceChecker 적용
		
		printf("%d\n", count);
	}

	return 0;
}