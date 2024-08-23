#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr int MAX = 101;
constexpr int cheese = 1;
constexpr int air = 0;
constexpr int air_in_cheese = -1;
int map[MAX][MAX] = {};
bool vis[MAX][MAX] = {};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row, col;

// air_in_cheese인지 air인지 세팅하는 함수
void find_air() {
	
	// 먼저 방문 배열 초기화
	for (int i = 0; i <= 100; i++) {
		fill(vis[i], vis[i] + MAX, false);
	}
	
	// 맵 테두리중 공기인 부분을 찾고 queue에 넣음
	queue<pair<int, int>> q;
	for (int i = 1; i <= row; i++) {
		if (map[i][1] == air) {
			vis[i][1] = true;
			q.push({ i, 1 });
		}
		if (map[i][col] == air) {
			vis[i][col] = true;
			q.push({ i, col });
		}
	}
	for (int j = 1; j <= col; j++) {
		if (map[1][j] == air) {
			vis[1][j] = true;
			q.push({ 1, j });
		}
		if (map[row][j] == air) {
			vis[row][j] = true;
			q.push({ row, j });
		}
	}

	// queue가 빌 때까지 BFS
	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int cx = q.front().second + dx[dir];
			int cy = q.front().first + dy[dir];

			// 맵을 나가거나 공기가 아니거나 방문을 했으면 continue;
			if (cx <= 0 || cx >= MAX || cy <= 0 || cy >= MAX) continue;
			if (map[cy][cx] == cheese || vis[cy][cx]) continue;

			// air_in_cheese 인데 방문 가능하면 이전 치즈 녹음으로 인해 air로 바뀐 장소
			if (map[cy][cx] == air_in_cheese) map[cy][cx] = air;

			vis[cy][cx] = true;
			q.push({ cy,cx });
		}
		q.pop();
	}

	// 맵에선 공기인데 방문한 적이 없으면 -> air_in_cheese
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (map[i][j] == air && !vis[i][j]) {
				map[i][j] = air_in_cheese;
			}
		}
	}
}

// 녹일 치즈가 있으면 녹이고 개수를 반환하는 함수
int melt_cheese() {

	// 녹는 치즈의 위치를 저장할 벡터
	vector<pair<int, int>> melting_cheese;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {

			// 현재 장소가 치즈면
			if (map[i][j] == cheese) {
				
				// 상하좌우로 air의 개수 확인
				int air_cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int cx = j + dx[dir];
					int cy = i + dy[dir];

					if (cx <= 0 || cx >= MAX || cy <= 0 || cy >= MAX) continue;

					if (map[cy][cx] == air) air_cnt++;
				}

				// air의 개수가 2개 이상이면 녹을 치즈
				if (air_cnt >= 2) melting_cheese.push_back({ i, j });
			}
		}
	}

	// 녹을 치즈를 air로 바꿈
	for (auto& pos : melting_cheese) map[pos.first][pos.second] = air;
	
	int melting_cheese_size = melting_cheese.size();

	return melting_cheese_size;
}

int main() {

	// 입력
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}

	int day = 0;
	while (1) {
		find_air();
		int how_many_cheese_to_melt = melt_cheese();
		
		// 녹을 치즈 개수가 0이면 모두 녹아 없어진 상태
		if (how_many_cheese_to_melt == 0) break;

		day++;
	}

	cout << day;

	return 0;
}