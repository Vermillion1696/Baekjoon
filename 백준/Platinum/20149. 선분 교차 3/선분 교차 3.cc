#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip> // setprecision 사용
#define pii pair<long long int, long long int>
using namespace std;

// 네 점의 좌표
pii point[4];

// 최대공약수 함수
long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// CCW 함수
int CCW(pii point1, pii point2, pii point3) {
    long long int result = (point2.first - point1.first) * (point3.second - point1.second) - (point3.first - point1.first) * (point2.second - point1.second);
    if (result > 0) return 1;    // 반시계방향
    if (result < 0) return -1;   // 시계방향
    return 0;                    // 일직선
}

// 교차 판별 함수 (일직선 포함)
bool intersect(pii point1, pii point2, pii point3, pii point4) {
    int p1p2CCW1 = CCW(point1, point2, point3);
    int p1p2CCW2 = CCW(point1, point2, point4);
    int p3p4CCW1 = CCW(point3, point4, point1);
    int p3p4CCW2 = CCW(point3, point4, point2);

    // 한 직선 위에 있으면
    if (p1p2CCW1 == 0 && p1p2CCW2 == 0 && p3p4CCW1 == 0 && p3p4CCW2 == 0) {
        if (point1 > point2) swap(point1, point2);
        if (point3 > point4) swap(point3, point4);
        return point3 <= point2 && point1 <= point4;
    }

    return (p1p2CCW1 * p1p2CCW2 <= 0) && (p3p4CCW1 * p3p4CCW2 <= 0);
}

// 교점 구하기
// 분모가 0이 되는 경우는 하단의 main 조건문에서 CCW가 0이 되므로 걸러진다
void intersectPoint(pii point1, pii point2, pii point3, pii point4) {
    long double x1 = point1.first, y1 = point1.second;
    long double x2 = point2.first, y2 = point2.second;
    long double x3 = point3.first, y3 = point3.second;
    long double x4 = point4.first, y4 = point4.second;

    long double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    long double numX = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    long double numY = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);

    long double x = numX / den;
    long double y = numY / den;

    // 0에 매우 근접한 값의 부호를 제거
    if (abs(x) < 1e-11) x = 0.0;
    if (abs(y) < 1e-11) y = 0.0;

    cout << "\n" << x << " " << y;
}

int main() {

    // 입력
    for (int i = 0; i < 4; i++) {
        cin >> point[i].first >> point[i].second;
    }

    // 교차 판별
    if (intersect(point[0], point[1], point[2], point[3])) {
        cout << 1;

        // 교차 + 두 벡터가 한 직선 위에 있지 않음
        if (CCW(point[0], point[1], point[2]) != 0 || CCW(point[0], point[1], point[3]) != 0 || CCW(point[2], point[3], point[0]) != 0 || CCW(point[2], point[3], point[1]) != 0) {
            cout << fixed << setprecision(11);
            intersectPoint(point[0], point[1], point[2], point[3]);
        }
        // 교차 + 두 벡터가 한 직선 위에 있음
        else {

            // 좌표 오름차순 놓기
            if (point[0] > point[1]) {
                swap(point[1], point[0]);
            }
            if (point[2] > point[3]) {
                swap(point[3], point[2]);
            }

            // 교점이 여러 개인 경우
            if (point[2] < point[1] && point[0] < point[3]) {
                return 0;
            }

            // 교점이 하나인 경우
            if (point[1] == point[2]) {
                cout << "\n" << point[1].first << " " << point[1].second;
            }
            else {
                cout << "\n" << point[0].first << " " << point[0].second;
            }
        }
    }
    else {
        cout << 0;
    }

    return 0;
}
