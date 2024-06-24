#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[1000][1000];
int day[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> Q;
	int row, column;
	cin >> column >> row;

	// board 입력, 그리고 1인 지점을 Queue에 넣음 (시작점)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> board[i][j];
			day[i][j] = 0;

			if (board[i][j] == 1) {
				Q.push(make_pair(i, j));
			}
		}
	}

	// BFS
	while (!Q.empty()) {
		pair<int, int> current = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = current.X + dx[dir];
			int ny = current.Y + dy[dir];

			if (nx < 0 || nx >= row || ny < 0 || ny >= column) {
				continue;
			}
			if (board[nx][ny] == -1 || board[nx][ny] == 1) {
				continue;
			}

			board[nx][ny] = 1;
			day[nx][ny] = day[current.X][current.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}

	// 다 익었는지 체크
	bool all1 = true;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			// (비었거나 익은) 게 아닌 것이 하나라도 있으면 false
			if (board[i][j] != -1 && board[i][j] != 1) {
				all1 = false;
				goto breakpoint;
			}
		}
	}
	breakpoint:

	if (all1) {
		int dayMAX = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (dayMAX < day[i][j]) {
					dayMAX = day[i][j];
				}
			}
		}
		cout << dayMAX;
	}
	else {
		cout << -1;
	}
	
	return 0;
}