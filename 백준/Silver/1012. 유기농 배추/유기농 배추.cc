#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second
#define MAX 51
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[MAX][MAX];
// 0 : 방문 불가, 1 : 미방문, 2 : 방문 완료

// 디버깅용 출력 함수
void BOARD(const int& row, const int& column) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

void BFS(const int& row, const int& column, const int& startY, const int& startX) {
	queue<pair<int, int>> q;
	board[startY][startX] = 2;
	q.push({ startY, startX });

	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().X + dx[i];
			int ny = q.front().Y + dy[i];

			if (nx < 1 || nx > column || ny < 1 || ny > row) continue;
			if (board[ny][nx] != 1) continue;

			board[ny][nx] = 2;
			q.push({ ny,nx });
		}
		q.pop();
		//BOARD(row, column);
		//cout << "\n";
	}

	return;
}

int main() {
	int tc, column, row, cabbage, worm;
	cin >> tc;

	while (tc--) {
		// 입력 초기화 세팅
		for (int i = 1; i < MAX; i++) {
			fill(board[i], board[i] + MAX, 0);
		}
		cin >> column >> row >> cabbage;
		worm = 0;

		int x, y;
		while (cabbage--) {
			cin >> x >> y;
			board[y + 1][x + 1] = 1;
		}

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= column; j++) {
				if (board[i][j] == 1) {
					worm++;
					BFS(row, column, i, j);
				}
			}
		}

		cout << worm << "\n";
	}

	return 0;
}