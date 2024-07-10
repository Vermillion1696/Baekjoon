#include <iostream>
#define MAX 129
#define ll long long
using namespace std;
bool board[MAX][MAX];

// 종이가 안 되면 -1 반환
// 파란 종이면 1 반환, 흰 종이면 0 반환
int isPaper(const int& n, const int& row, const int& column) {

	bool base = board[row][column];
	
	for (int i = row; i < row + n; i++) {
		for (int j = column; j < column + n; j++) {
			if (base != board[i][j]) return -1;
		}
	}
	
	return base;
}

void paper(int n, int row, int column, int& white, int& blue) {

	int ispaper = isPaper(n, row, column);

	// 판별 결과에 따른 숫자 더하기
	if (ispaper == 1) {
		blue++;
		return;
	}
	else if (ispaper == 0) {
		white++;
		return;
	}
	
	// 1/4 영역 전개 (료이키 텐카이)
	paper(n / 2, row, column, white, blue);
	paper(n / 2, row, column + n / 2, white, blue);
	paper(n / 2, row + n / 2, column, white, blue);
	paper(n / 2, row + n / 2, column + n / 2, white, blue);

	return;
}

int main() {
	int n;
	cin >> n;

	for (int row = 1; row <= n; row++) {
		for (int column = 1; column <= n; column++) {
			cin >> board[row][column];
		}
	}

	int white = 0, blue = 0;

	paper(n, 1, 1, white, blue);
	cout << white << "\n" << blue;

	return 0;
}