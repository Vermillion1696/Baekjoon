#include <iostream>
#include <queue>
#include <tuple>
#define MAX 31
using namespace std;

// 0 : 미방문, n : 도달 시간 n
int map[MAX][MAX][MAX];
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };
int dim, row, col;

class point {
public:
	int x, y, z;
};

point S, E;

// 맵 세팅 함수
void map_set() {
	
	char c;
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= row; j++) {
			for (int k = 1; k <= col; k++) {
				
				// 입구 출구 좌표 저장
				cin >> c;
				if (c == 'S') {
					S.x = k;
					S.y = j;
					S.z = i;
				}
				else if (c == 'E') {
					E.x = k;
					E.y = j;
					E.z = i;
				}

				// 방문 불가능 점
				if (c == '#') map[i][j][k] = -1;
				else map[i][j][k] = 0;

			}
		}
	}

	return;
}

void BFS() {
	
	// x, y, z, generation
	queue<tuple<int, int, int, int>> q;
	q.push({ S.x, S.y, S.z, 1 });
	map[S.z][S.y][S.x] = 1;

	while (!q.empty()) {
		for (int dir = 0; dir < 6; dir++) {
			int cur_x = get<0>(q.front()) + dx[dir];
			int cur_y = get<1>(q.front()) + dy[dir];
			int cur_z = get<2>(q.front()) + dz[dir];
			
			if (cur_x < 1 || cur_x > col || cur_y < 1 || cur_y > row || cur_z < 1 || cur_z > dim) continue;
			if (map[cur_z][cur_y][cur_x] != 0) continue;

			q.push({ cur_x, cur_y, cur_z, get<3>(q.front()) + 1 });
			map[cur_z][cur_y][cur_x] = get<3>(q.front());
		}
		q.pop();
	}

	// 시작점 도달 시간을 1로 했으므로 수정
	map[S.z][S.y][S.x] = 0;

	return;
}

// 디버깅용 맵 출력 함수
void map_print() {
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= row; j++) {
			for (int k = 1; k <= col; k++) {
				cout << map[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return;
}

int main() {
	
	while (1) {
		cin >> dim >> row >> col;

		if (dim == 0 && row == 0 && col == 0) break;

		map_set();
		BFS();

		if (map[E.z][E.y][E.x] == 0) cout << "Trapped!\n";
		else cout << "Escaped in " << map[E.z][E.y][E.x] << " minute(s).\n";
		//map_print();
	}

	return 0;
}