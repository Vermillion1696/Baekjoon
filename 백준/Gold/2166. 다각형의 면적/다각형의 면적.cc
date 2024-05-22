#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 좌표를 담을 벡터
vector<pair<double, double>> v;

// 신발끈 공식 함수
long double S(double x1, double y1, double x2, double y2, double x3, double y3) {
	long double total = ((x1 * y2) + (x2 * y3) + (x3 * y1)) - ((y1 * x2) + (y2 * x3) + (y3 * x1));
	return total / 2;
}

int main() {

	// 개수 입력
	int n;
	cin >> n;

	// 좌표 입력
	double x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	// 넓이 구하기
	long double total = 0;
	for (int i = 1; i < n - 1; i++) {
		total += S(v[0].first, v[0].second, v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	}

	// 출력
	cout << fixed;
	cout.precision(1);
	cout << fabs(total);

	return 0;
}