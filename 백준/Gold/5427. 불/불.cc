#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define Y first
#define X second
#define MAX 1001

// map[z][~][~]
// z == 0 : map
// z == 1 : 지훈이가 칸에 도달하는 데 걸린 시간 저장
// z == 2 : 불이 칸에 도달하는 데 걸린 시간
#define B 0
#define P 1
#define F 2
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

// map[z][~][~] 에 대해 z : B 이면...
// 0 : 길
// 1 : 지훈
// 2 : 불
// 3 : 벽
// map[z][~][~] 에 대해 z : P or F 이면...
// -1 : 못 가는 곳
// 0 : 안 간 곳
// + : 간 곳 (시간)

// 맵 초기 세팅 함수
void fillMAP(int map[3][MAX][MAX], const int& row, const int& column) {
	char c;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cin >> c;
			if (c == '.') {
				map[B][i][j] = 0;
			}
			else if (c == '@') {
				map[B][i][j] = 1;
				map[P][i][j] = 0;
			}
			else if (c == '*') {
				map[B][i][j] = 2;
				map[P][i][j] = -1;
				map[F][i][j] = 0;
			}
			else {
				map[B][i][j] = 3;
				map[P][i][j] = -1;
				map[F][i][j] = -1;
			}
		}
	}
}

// 디버깅용 출력 함수
void printMAP(int map[3][MAX][MAX], const int& dimension, const int& row, const int& column) {
	cout << "\n";
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cout << map[dimension][i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

// player BFS
void PBFS(int map[3][MAX][MAX], queue<pair<int, int>> &q, const int& row, const int& column) {
	while (!q.empty()) {
		int y, x;
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny <= 0 || ny > row || nx <= 0 || nx > column) {
				continue;
			}
			// 길만 잡아먹는다
			if (map[P][ny][nx] != 0 || map[B][ny][nx] != 0) {
				continue;
			}

			map[P][ny][nx] = map[P][y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	return;
}

// fire BFS
void FBFS(int map[3][MAX][MAX], queue<pair<int, int>>& q, const int& row, const int& column) {
	while (!q.empty()) {
		int y, x;
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny <= 0 || ny > row || nx <= 0 || nx > column) {
				continue;
			}
			// 불 또는 벽이면 continue; (길, 사람은 잡아먹는다)
			if (map[F][ny][nx] != 0 || map[B][ny][nx] == 2 || map[B][ny][nx] == 3) {
				continue;
			}

			map[F][ny][nx] = map[F][y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	return;
}

// 시작점이 탈출구인지 반환하는 함수
bool isBoundary(int map[3][MAX][MAX], const int& row, const int& column) {
	for (int i = 1; i <= row; i++) {
		if (map[B][i][1] == 1 || map[B][i][column] == 1) {
			return 1;
		}
	}
	for (int j = 1; j <= column; j++) {
		if (map[B][1][j] == 1 || map[B][row][j] == 1) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int map[3][MAX][MAX] = {};
		int row, column;
		cin >> column >> row;

		fillMAP(map, row, column);

		// 시작점 입력 받아 각각 큐에 넣기
		queue<pair<int, int>> PQ;
		queue<pair<int, int>> FQ;
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= column; j++) {
				if (map[B][i][j] == 1) {
					PQ.push(make_pair(i, j));
				}
				else if (map[B][i][j] == 2) {
					FQ.push(make_pair(i, j));
				}
			}
		}

		// Player에 대한 BFS, Fire에 대한 BFS를 각각 돌림
		PBFS(map, PQ, row, column);
		FBFS(map, FQ, row, column);

		// BFS를 하고도 0이 남아있으면 고립된 위치이므로 (불이 방문 불가), -1로 바꿔야 한다.
		// P : map[P][i][j] == 0 (방문 가능) 인데 map[B][i][j] != 1 (시작점이 아니면) -> -1로
		// F : map[F][i][j] == 0 (방문 가능) 인데 map[B][i][j] != 2 (시작점이 아니면) -> -1로
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= column; j++) {
				if (map[F][i][j] == 0 && map[B][i][j] != 2) {
					map[F][i][j] = -1;
				}
				if (map[P][i][j] == 0 && map[B][i][j] != 1) {
					map[P][i][j] = -1;
				}
			}
		}

		//printMAP(F, row, column);
		//printMAP(P, row, column);
		//printMAP(B, row, column);

		// 가장자리까지 가는 최소 시간 찾기
		int minTIME = MAX * MAX;
		for (int i = 1; i <= row; i++) {
			// 길이면서 도달가능 + (플레이어 도달 시간 < 불 도달 시간) 또는 (불 도착 불가) + (탈출구 도달 시간 < 최소 시간)   
			if (map[B][i][1] == 0 && map[P][i][1] != -1 && (map[P][i][1] < map[F][i][1] || map[F][i][1] == -1) && map[P][i][1] < minTIME) {
				minTIME = map[P][i][1];
			}
			if (map[B][i][column] == 0 && map[P][i][column] != -1 && (map[P][i][column] < map[F][i][column] || map[F][i][column] == -1) && map[P][i][column] < minTIME) {
				minTIME = map[P][i][column];
			}
		}
		for (int j = 1; j <= column; j++) {
			if (map[B][1][j] == 0 && map[P][1][j] != -1 && (map[P][1][j] < map[F][1][j] || map[F][1][j] == -1) && map[P][1][j] < minTIME) {
				minTIME = map[P][1][j];
			}
			if (map[B][row][j] == 0 && map[P][row][j] != -1 && (map[P][row][j] < map[F][row][j] || map[F][row][j] == -1) && map[P][row][j] < minTIME) {
				minTIME = map[P][row][j];
			}
		}

		// 가장자리가 시작점이면
		if (isBoundary(map, row, column)) {
			cout << 1 << "\n";
		}
		// 불가능 판정이면
		else if (minTIME == MAX * MAX) {
			cout << "IMPOSSIBLE" << "\n";
		}
		// 가장자리까지 가는 최소 시간이므로 +1
		else {
			cout << minTIME + 1 << "\n";
		}
	}
	return 0;
}