#include <iostream>
using namespace std;

// 좌표 구조체 선언
typedef struct pos {
	int x;
	int y;
} pos;
pos Point[3];

// CCW 함수
int CCW(pos Point[]) {
	int m = (Point[1].x - Point[0].x) * (Point[2].y - Point[0].y) - (Point[2].x - Point[0].x) * (Point[1].y - Point[0].y);
	if (m > 0) {
		return 1;
	}
	else if (m == 0) {
		return 0;
	}
	else {
		return -1;
	}

}

int main() {

	// 입력
	for (int i = 0; i < 3; i++) {
		cin >> Point[i].x >> Point[i].y;
	}

	// 출력
	cout << CCW(Point);

	return 0;
}