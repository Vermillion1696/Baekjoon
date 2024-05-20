#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// 자릿수 세팅
	cout << fixed;
	cout.precision(10);

	// 좌표 구조체 선언
	typedef struct pos {
		int x;
		int y;
	} pos;
	pos point[3];

	// 불가능 판정 변수
	bool tf = 1;

	// 좌표 입력
	for (int i = 0; i < 3; i++) {
		cin >> point[i].x >> point[i].y;
	}
	
	// 삼각형 넓이가 0이면 평행사변형 역시 만들 수 없다
	// 또한, 두 벡터의 외적 크기는 삼각형의 넓이
	if ((point[1].x - point[0].x) * (point[2].y - point[0].y) - (point[2].x - point[0].x) * (point[1].y - point[0].y) == 0) {
		tf = 0;
	}

	// 각 케이스에 케이스별 둘레 값 저장
	double c[3];
	for (int i = 0; i < 3; i++) {
		c[i] = 2 * sqrt((point[i % 3].x - point[(i + 1) % 3].x) * (point[i % 3].x - point[(i + 1) % 3].x) + (point[i % 3].y - point[(i + 1) % 3].y) * (point[i % 3].y - point[(i + 1) % 3].y));
	}

	// 정렬
	sort(c, c + 3);

	// 출력
	tf ? cout << c[2] - c[0] : cout << -1.0000000000;

	return 0;
}