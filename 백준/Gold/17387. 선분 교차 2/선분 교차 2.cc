#include <iostream>
#include <utility>
#define pii pair<long long int, long long int>
using namespace std;

pii point[4];

int CCW(pii point1, pii point2, pii point3) {
	long long int result = (point2.first - point1.first) * (point3.second - point2.second) - (point3.first - point2.first) * (point2.second - point1.second);
	
	// 시계방향 -1
	if (result < 0) {
		return -1;
	}
	// 반시계방향 1
	else if (result > 0) {
		return 1;
	}
	// 일직선 0
	else {
		return 0;
	}
}

bool intersect(pii point1, pii point2, pii point3, pii point4) {
	int p1p2CCW = CCW(point1, point2, point3) * CCW(point1, point2, point4);
	int p3p4CCW = CCW(point3, point4, point1) * CCW(point3, point4, point2);

	// 한 직선 위에 있으면
	if (p1p2CCW == 0 && p3p4CCW == 0) {

		// 좌표 오름차순 놓기
		if (point1 > point2) {
			swap(point2, point1);
		}
		if (point3 > point4) {
			swap(point3, point4);
		}

		// 교점이 있으면 만족
		return point3 <= point2 && point1 <= point4;
	}

	// p1p2 선분 && p3, p4로도 만나고, p3p4 선분 && p1, p2로도 만난다
	return p1p2CCW <= 0 && p3p4CCW <= 0;
}

int main() {

	// 입력
	for (int i = 0; i < 4; i++) {
		cin >> point[i].first >> point[i].second;
	}

	// 출력
	cout << intersect(point[0], point[1], point[2], point[3]);

	return 0;
}