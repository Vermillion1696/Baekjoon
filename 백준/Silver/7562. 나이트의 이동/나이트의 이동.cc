#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#define MAX 301
#define x first
#define y second
using namespace std;

int vis[MAX][MAX];
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1 };

// 맵을 초기화 해주는 함수
void mapCLEAR() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			vis[i][j] = -1;
		}
	}
	return;
}

// 디버깅용 맵 출력 함수
void mapPRINT(const int& n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
}

void BFS(const int& row, const int& column, const int& size) {
	queue<tuple<int, int, int>> q;
	int generation = 0;
	vis[row][column] = generation;
	q.push({ column, row, generation + 1 });

	while (!q.empty()) {
		for (int dir = 0; dir < 8; dir++) {
			int cur_x = get<0>(q.front()) + dx[dir];
			int cur_y = get<1>(q.front()) + dy[dir];

			if (cur_x < 1 || cur_x > size || cur_y < 1 || cur_y > size) continue;
			if (vis[cur_y][cur_x] != -1) continue;

			vis[cur_y][cur_x] = get<2>(q.front());
			q.push({ cur_x, cur_y, get<2>(q.front()) + 1});
		}
		//mapPRINT(size);
		q.pop();
	}

	return;
}

int main() {
	int tc, n;
	pair<int, int> start, end;
	cin >> tc;

	while (tc--) {
		mapCLEAR();

		cin >> n;
		cin >> start.x >> start.y >> end.x >> end.y;

		// 0~L-1을 1~L로 바꾸기 위한 작업
		start.x++;
		start.y++;
		end.x++;
		end.y++;

		BFS(start.y, start.x, n);
		cout << vis[end.y][end.x] << "\n";
	}

	return 0;
}