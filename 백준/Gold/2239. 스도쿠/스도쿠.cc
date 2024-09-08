#include <iostream>
#include <vector>

using namespace std;

bool is_used_row[9][9];
bool is_used_col[9][9];
bool is_used_box[9][9];

int map[9][9];
int result_map[9][9];
int zero_count = 0;
bool solved = false;

// 빈 칸 좌표 저장
vector<pair<int, int>> empty_cells;

void back_tracking(int k) {

	// 기저 조건
	if (k == zero_count) {
		solved = true;
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				result_map[y][x] = map[y][x];
			}
		}
		return;
	}

	// 현재 빈 칸의 좌표를 가져옴
	int y = empty_cells[k].first;
	int x = empty_cells[k].second;

	// 1부터 9까지 가능한 숫자를 찾음
	for (int num = 1; num <= 9; num++) {
		if (is_used_row[num - 1][y]) continue;
		if (is_used_col[num - 1][x]) continue;
		if (is_used_box[num - 1][y / 3 * 3 + x / 3]) continue;

		map[y][x] = num;

		is_used_row[num - 1][y] = true;
		is_used_col[num - 1][x] = true;
		is_used_box[num - 1][y / 3 * 3 + x / 3] = true;

		// 다음 빈 칸 탐색
		back_tracking(k + 1);

		if (solved) return;

		// 백트래킹: 다시 초기화
		is_used_row[num - 1][y] = false;
		is_used_col[num - 1][x] = false;
		is_used_box[num - 1][y / 3 * 3 + x / 3] = false;
		map[y][x] = 0;
	}

	return;
}

int main() {

	// 입력
	char c;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> c;
			map[y][x] = c - '0';

			if (map[y][x] == 0) {
				empty_cells.push_back({ y, x });
				zero_count++;
			}
			else {
				int num = map[y][x];
				is_used_row[num - 1][y] = true;
				is_used_col[num - 1][x] = true;
				is_used_box[num - 1][y / 3 * 3 + x / 3] = true;
			}
		}
	}

	back_tracking(0);

	// 출력
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << result_map[y][x];
		}
		cout << '\n';
	}

	return 0;
}