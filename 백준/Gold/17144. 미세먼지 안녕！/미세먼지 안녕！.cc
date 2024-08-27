#include <iostream>
#include <utility>
#include <vector>
using namespace std;
constexpr int MAX = 51;

int map[MAX][MAX];
int lazy_map[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row, col;
vector<pair<int, int>> air_cond;

// 디버깅용 맵 출력 함수
void map_print() {
	cout << '\n';
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

// 먼지 이동 함수
void dust_move() {

	// lazy 갱신 맵 초기화
	for (int i = 0; i < MAX; i++) {
		fill(lazy_map[i], lazy_map[i] + MAX, 0);
	}

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (map[i][j] > 0) {

				// 확산되는 방향 수 카운트
				int divide_dir = 0;
				for (int dir = 0; dir < 4; dir++) {
					int cx = j + dx[dir];
					int cy = i + dy[dir];

					if (cx < 1 || cx > col || cy < 1 || cy > row) continue;

					if (map[cy][cx] != -1) divide_dir++;
				}

				// lazy_map에 확산 개수 저장
				int dust_to_move = map[i][j] / 5;
				for (int dir = 0; dir < 4; dir++) {
					int cx = j + dx[dir];
					int cy = i + dy[dir];

					if (cx < 1 || cx > col || cy < 1 || cy > row) continue;
					if (map[cy][cx] == -1) continue;

					lazy_map[cy][cx] += dust_to_move;
				}

				lazy_map[i][j] -= dust_to_move * divide_dir;
			}
		}
	}

	// 모든 방향 확산이 끝나면 갱신
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			map[i][j] += lazy_map[i][j];
		}
	}

	return;
}

// 공기 회전 함수
void air_move() {

	int air_x, air_y;
	
	// 위쪽 방향 공기청정기 위치 (반시계)
	air_x = air_cond[0].second;
	air_y = air_cond[0].first;

	// 아래쪽 변
	for (int i = air_y; i > 1; i--) {
		swap(map[i][1], map[i - 1][1]);
	}
	
	// 오른쪽 변
	for (int j = 1; j < col; j++) {
		swap(map[1][j], map[1][j + 1]);
	}

	// 위쪽 변
	for (int i = 1; i < air_y; i++) {
		swap(map[i][col], map[i + 1][col]);
	}

	// 왼쪽 변
	for (int j = col; j > 1; j--) {
		swap(map[air_y][j], map[air_y][j - 1]);
	}

	// 방금 공기가 회전하며 청정된 칸
	map[air_y][air_x + 1] = 0;


	// 아래쪽 방향 공기청정기 위치 (시계)
	air_x = air_cond[1].second;
	air_y = air_cond[1].first;

	// 왼쪽 변
	for (int i = air_y; i < row; i++) {
		swap(map[i][1], map[i + 1][1]);
	}

	// 아래쪽 변
	for (int j = 1; j < col; j++) {
		swap(map[row][j], map[row][j + 1]);
	}

	// 오른쪽 변
	for (int i = row; i > air_y; i--) {
		swap(map[i][col], map[i - 1][col]);
	}

	// 위쪽 변
	for (int j = col; j > 1; j--) {
		swap(map[air_y][j], map[air_y][j - 1]);
	}

	// 방금 공기가 회전하며 청정된 칸
	map[air_y][air_x + 1] = 0;

	return;
}

int main() {
	int time;
	cin >> row >> col >> time;

	// 입력
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];

			// 청정기의 위치 저장
			if (map[i][j] == -1) {
				air_cond.push_back({ i, j });
			}
		}
	}

	while (time--) {
		dust_move();
		air_move();
	}

	// 출력
	long long int total = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (map[i][j] != -1) total += map[i][j];
		}
	}

	cout << total;

	return 0;
}