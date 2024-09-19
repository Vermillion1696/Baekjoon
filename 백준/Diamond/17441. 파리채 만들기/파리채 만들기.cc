#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	// 입력
	int N;
	cin >> N;
	vector<double> x_list(N);
	vector<double> y_list(N);
	for (int i = 0; i < N; ++i) {
		cin >> x_list[i] >> y_list[i];
	}

	double area = 0.0;
	double qx = 0.0, qy = 0.0, ixx = 0.0, iyy = 0.0;
	for (int i = 0; i < N; ++i) {

		// 다각형 꼭짓점 순회
		double x0 = x_list[i];
		double y0 = y_list[i];
		double x1 = x_list[(i + 1) % N];
		double y1 = y_list[(i + 1) % N];
		double cross = x0 * y1 - x1 * y0;

		// 넓이합, x적분합, y적분합, y^2적분합, x^2적분합
		area += cross;
		qx += (x0 + x1) * cross;
		qy += (y0 + y1) * cross;
		ixx += (y0 * y0 + y0 * y1 + y1 * y1) * cross;
		iyy += (x0 * x0 + x0 * x1 + x1 * x1) * cross;
	}
	
	// 이를 
	// 1차모멘트 Qx, Qy
	// 2차모멘트 Ixx, Iyy
	// 실제 다각형의 넓이 (신발끈 공식)
	// 로 변환
	qx /= 6.0;
	qy /= 6.0;
	ixx /= 12.0;
	iyy /= 12.0;
	area *= 0.5;

	// x, y 기댓값
	double ex = qx / area, ey = qy / area;

	// x^2, y^2 기댓값
	double ex2 = iyy / area, ey2 = ixx / area;

	// x, y의 분산
	double var_x = ex2 - ex * ex, var_y = ey2 - ey * ey;

	// 독립 확률변수 x, y에 대해 두 점 사이 거리 제곱의 기댓값
	// -> 2(var_x + var_y)
	double expected_d2 = 2 * (var_x + var_y);
	
	cout << fixed << setprecision(10) << expected_d2;

	return 0;
}