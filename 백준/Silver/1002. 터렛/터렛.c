#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int distanceChecker(int x1, int y1, int r1, int x2, int y2, int r2) {
	double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		return -1;
	} // 다 같을 때는 -1

	if (r1 + r2 < distance) {
		return 0;
	}
	else if ((r1 + r2) * (r1 + r2) == (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) {
		return 1;
	} // 소수점을 포함하는 sqrt는 == 연산자를 사용할 수 없음
	else if (abs(r1 - r2) < distance && (r1 + r2) > distance) {
		return 2;
	}
	else if ((r1 - r2) * (r1 - r2) == (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) {
		return 1;
	} // 2번과 동치
	else if (abs(r1 - r2) > distance) {
		return 0;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", distanceChecker(x1, y1, r1, x2, y2, r2));
	}

	return 0;
}