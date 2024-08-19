#include <iostream>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
constexpr int MAX = 3072;
char map[MAX][MAX * 2];

// 시작점은 세모 모양 제일 위 점 기준
void draw(int n, int start_row, int start_col) {
	
	// base condition
	if (n == 3) {

		// 1번째 줄
		map[start_row][start_col] = '*';

		// 2번째 줄
		map[start_row + 1][start_col - 1] = '*';
		map[start_row + 1][start_col + 1] = '*';
		
		// 3번째 줄
		for (int dx = -2; dx <= 2; dx++) {
			map[start_row + 2][start_col + dx] = '*';
		}
	}
	else {

		// 삼각형 모양으로 그림
		draw(n / 2, start_row, start_col);
		draw(n / 2, start_row + n / 2, start_col - n / 2);
		draw(n / 2, start_row + n / 2, start_col + n / 2);
	}

	return;
}

int main() {
	fast_output;

	// map을 빈칸으로 모두 채우기
	for (int i = 0; i < MAX; i++) {
		fill(map[i], map[i] + 2 * MAX, ' ');
	}

	int n;
	cin >> n;

	draw(n, 0, n - 1);

	// 출력
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n * 2; col++) {
			cout << map[row][col];
		}
		cout << "\n";
	}

	return 0;
}