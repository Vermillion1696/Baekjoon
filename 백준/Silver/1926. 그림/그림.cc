#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

// 판, 방문 여부
int board[500][500];
int vis[500][500] = { 0, };

int main() {

	// 입력
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int max = 0;
	int size = 0;
	int drawing = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			// 1이면서 방문하지 않았으면 시작점으로 잡음
			if (board[i][j] == 1 && !vis[i][j]) {
				queue<pair<int, int>> Q;
				vis[i][j] = true;
				Q.push(make_pair(i, j));
				size = 1;

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
						if (vis[nx][ny] || board[nx][ny] != 1) {
							continue;
						}

						size++;
						vis[nx][ny] = 1;
						Q.push(make_pair(nx, ny));
					}
				}

				drawing++;
				size > max ? max = size : max = max;
			}
		}
	}

	cout << drawing << "\n" << max;
	
	return 0;
}