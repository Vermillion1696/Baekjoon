#include <iostream>
using namespace std;
constexpr int MAX = 65;
// 한 구역이 아님을 나타내는 const int 정수
constexpr int not_area = -1;
bool board[MAX][MAX];

// 검사 구역이 한 구역이면 그 정수 반환, 아니면 not_area 반환
int is_area(int N, int start_row, int start_col) {
	int cur_num = board[start_row][start_col];
	for (int row = start_row; row < start_row + N; row++) {
		for (int col = start_col; col < start_col + N; col++) {

			// 만약 검사 영역이 한 구역이 아니면 not_area 반환
			if (board[row][col] != cur_num) return not_area;
		}
	}

	return cur_num;
}

void area_code(int N, int start_row, int start_col) {

	// base condition은 영역 크기가 1인 경우
	if (N == 1) {
		bool num = board[start_row][start_col];
		if (num == true) cout << 1;
		else cout << 0;
	}
	else {
		int num = is_area(N, start_row, start_col);

		// 구역 판정이면
		if (num > not_area) {
			if (num == true) cout << 1;
			else cout << 0;
		}
		// 구역 판정이 아니면 4등분 후 작은 영역으로 다시 판정
		else {
			cout << '(';
			for (int dy = 0; dy < N; dy += N / 2) {
				for (int dx = 0; dx < N; dx += N / 2) {
					area_code(N / 2, start_row + dy, start_col + dx);
				}
			}
			cout << ')';
		}
	}

	return;
}

int main() {
	int N;
	char c;
	cin >> N;
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			cin >> c;
			board[row][col] = c - '0';
		}
	}

	area_code(N, 1, 1);

	return 0;
}