#include <iostream>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
constexpr int MAX = 21;
bool is_used[26];
int map[MAX][MAX];
int row, col;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int max_cnt = 0;

// 백트래킹
void back_tracking(int total_move, int x, int y) {

	// 상하좌우로 움직일 수 있는 칸 확인
	for (int dir = 0; dir < 4; dir++) {
		int cur_x = x + dx[dir];
		int cur_y = y + dy[dir];
		int cur_value = map[cur_y][cur_x];

		// 못 가는 곳이면 continue;
		if (cur_x < 1 || cur_x > col || cur_y < 1 || cur_y > row) continue;
		if (is_used[cur_value]) continue;

		// 갈 수 있는 곳 찾으면 (이동 수) + 1 후 재귀
		is_used[cur_value] = true;
		back_tracking(total_move + 1, cur_x, cur_y);
		is_used[cur_value] = false;
	}

	// 반복문이 끝나면 현재 이동 불가
	// -> 최대 횟수와 max();
	max_cnt = max(max_cnt, total_move);

	return;
}


int main() {
	fast_output;

	cin >> row >> col;

	char c;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> c;
			map[i][j] = c - 'A';
		}
	}

	is_used[map[1][1]] = true;
	back_tracking(0, 1, 1);

	cout << max_cnt + 1;
}