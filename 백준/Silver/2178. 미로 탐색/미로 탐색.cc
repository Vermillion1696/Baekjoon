#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

// 판, 거리
int board[100][100];
int dis[100][100];

int main() {

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			dis[i][j] = -1;
		}
	}

	// 입력이 붙어서 오므로 한 글자씩 받는 char 이용
	int n, m;
	char t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> t;
			if (t - '0' == 1) {
				board[i][j] = 1;
			}
			else {
				board[i][j] = 0;
			}
		}
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	// 0, 0 시작점
	queue<pair<int, int>> Q;
	Q.push(make_pair(0, 0));
	dis[0][0] = 0;

	// BFS
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny] == 0 || dis[nx][ny] != -1) {
				continue;
			}

			// 이전 거리 + 1이 현재 거리
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
	
	cout << dis[n - 1][m - 1] + 1;
	
	return 0;
}