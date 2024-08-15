#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1001
using namespace std;
int dist[MAX][MAX]; // main 외부에 선언시 0으로 초기화된 상태
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row, col;
int startX, startY;

void map_set() {
	int value;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> value;

			switch (value) {
			case 0:
				dist[i][j] = -1;
				break;
			case 2:
				startX = j;
				startY = i;
				break;
			}
		}
	}

	return;
}

void BFS() {
	// x, y, gen
	queue<tuple<int, int, int>> q;
	q.push({ startX, startY, 0 });
	dist[startY][startX] = 1;

	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int cur_x = get<0>(q.front()) + dx[dir];
			int cur_y = get<1>(q.front()) + dy[dir];
			int cur_gen = get<2>(q.front());

			if (cur_x < 1 || cur_x > col || cur_y < 1 || cur_y > row) continue;
			if (dist[cur_y][cur_x] != 0) continue;

			dist[cur_y][cur_x] = cur_gen + 1;
			q.push({ cur_x, cur_y, cur_gen + 1 });
		}
		q.pop();
	}

	// BFS 조건을 위해 1로 만들었던 시작점을 0으로 다시 바꿈
	dist[startY][startX] = 0;

	return;
}

int main() {
	cin >> row >> col;

	map_set();
	BFS();
	
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (i == startY && j == startX) cout << 0;
			else if (dist[i][j] == -1) cout << 0;
			else if (dist[i][j] == 0) cout << -1;
			else cout << dist[i][j];

			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}