#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int map[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map_size;

void BFS(const int& row, const int& column, const int& rain) {
	queue<pair<int, int>> q;
	vis[row][column] = true;
	q.push({ column, row });

	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int cur_x = q.front().first + dx[dir];
			int cur_y = q.front().second + dy[dir];

			if (cur_x <= 0 || cur_x >= MAX || cur_y <= 0 || cur_y >= MAX) continue;
			if (map[cur_y][cur_x] <= rain || vis[cur_y][cur_x]) continue;

			q.push({ cur_x, cur_y });
			vis[cur_y][cur_x] = true;
		}
		q.pop();
	}
	
	return;
}

// vis 초기화 함수
void visCLEAR() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			vis[i][j] = false;
		}
	}

	return;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> map_size;
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			cin >> map[i][j];
		}
	}
	
	// 1부터 100까지
	int max_area_cnt = 0;
	for (int rain = 0; rain <= 100; rain++) {
		visCLEAR();

		int area_cnt = 0;
		for (int i = 1; i <= map_size; i++) {
			for (int j = 1; j <= map_size; j++) {
				if (map[i][j] > rain && !vis[i][j]) {
					BFS(i, j, rain);
					area_cnt++;
				}
			}
		}
		//cout << area_cnt << " ";
		if (max_area_cnt < area_cnt) max_area_cnt = area_cnt;
	}

	cout << max_area_cnt;

	return 0;
}