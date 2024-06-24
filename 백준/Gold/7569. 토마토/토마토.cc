#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int board[100][100][100];
int day[100][100][100];
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<tuple<int, int, int>> Q;
	int row, column, depth;
	cin >> column >> row >> depth;

	// board 입력, 그리고 1인 지점을 Queue에 넣음 (시작점)
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < column; k++) {
				cin >> board[i][j][k];
				day[i][j][k] = 0;

				if (board[i][j][k] == 1) {
					Q.push(make_tuple(i, j, k));
				}
			}
		}
	}

	// BFS
	while (!Q.empty()) {
		tuple<int, int, int> current = Q.front();
		Q.pop();


		// 0, 1, 2 순서대로 depth, row, column
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<2>(current) + dx[dir];
			int ny = get<1>(current) + dy[dir];
			int nz = get<0>(current) + dz[dir];

			if (nx < 0 || nx >= column || ny < 0 || ny >= row || nz < 0 || nz >= depth) {
				continue;
			}
			if (board[nz][ny][nx] == -1 || board[nz][ny][nx] == 1) {
				continue;
			}

			board[nz][ny][nx] = 1;
			day[nz][ny][nx] = day[get<0>(current)][get<1>(current)][get<2>(current)] + 1;
			Q.push(make_tuple(nz, ny, nx));
		}
	}

	// 다 익었는지 체크
	bool all1 = true;
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < column; k++) {
				// (비었거나 익은) 게 아닌 것이 하나라도 있으면 false
				if (board[i][j][k] != -1 && board[i][j][k] != 1) {
					all1 = false;
					goto breakpoint;
				}
			}
		}
	}
	breakpoint:

	if (all1) {
		int dayMAX = 0;
		for (int i = 0; i < depth; i++) {
			for (int j = 0; j < row; j++) {
				for (int k = 0; k < column; k++) {
					if (dayMAX < day[i][j][k]) {
						dayMAX = day[i][j][k];
					}
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