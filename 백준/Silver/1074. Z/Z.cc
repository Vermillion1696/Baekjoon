#include <iostream>
using namespace std;

void Z(int row, int column, int n, long long current) {

    // n == 0은 size가 1인 사각형이다. 즉, 그 좌표
    if (n == 0) {
        cout << current;
        return;
    }

    // 비트 시프트를 사용한 연산
    int half = 1 << (n - 1);
    long long size = 1LL << (2 * (n - 1));

    // 중심을 기준으로 사분면 판단,
    // 보정값인 size를 더해서 넣어준다
    if (row < half && column < half) {
        Z(row, column, n - 1, current);
    }
    else if (row < half && column >= half) {
        Z(row, column - half, n - 1, current + size);
    }
    else if (row >= half && column < half) {
        Z(row - half, column, n - 1, current + 2 * size);
    }
    else {
        Z(row - half, column - half, n - 1, current + 3 * size);
    }
}

int main() {
    int n, row, column;
    cin >> n >> row >> column;
    Z(row, column, n, 0);
    return 0;
}