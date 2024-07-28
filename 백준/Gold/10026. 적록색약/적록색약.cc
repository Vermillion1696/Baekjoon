#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
#define MAX 101

// map : 실제 필드, vis : 방문 여부
char map[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(const int& row, const int& column, const bool& disable, const int& n) {
	queue<pair<int, int>> q;
	char current = map[row][column];
	vis[row][column] = true;
	q.push({ column,row });

	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = q.front().first + dx[dir];
			int ny = q.front().second + dy[dir];

			// 기본 BFS 조건
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (vis[ny][nx]) continue;

			// 색맹 여부에 따른 조건 분기
			if (!disable) {
				if (map[ny][nx] != current) continue;
			}
			else {
				if ((current == 'R' || current == 'G') && map[ny][nx] == 'B') continue;
				if (current == 'B' && (map[ny][nx] == 'R' || map[ny][nx] == 'G')) continue;
			}

			vis[ny][nx] = true;
			q.push({ nx, ny });
		}
		q.pop();
	}

	return;
}

int main() {
	int n;
	cin >> n;

	// 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int time = 0; time <= 1; time++) {

		// 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vis[i][j] = false;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!vis[i][j]) {
					BFS(i, j, time, n);
					cnt++;
				}
			}
		}

		cout << cnt << " ";
	}
}