#include <iostream>
using namespace std;
constexpr int MAX = 2188;
// 한 구역이 아님을 나타내는 const int 정수
constexpr int not_area = -2;
int board[MAX][MAX];
int m_one, zero, one;

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

void paper_cnt(int N, int start_row, int start_col) {

	// base condition은 종이 크기가 1인 경우
	if (N == 1) {
		int num = board[start_row][start_col];
		if (num == 1) one++;
		else if (num == 0) zero++;
		else m_one++;
	}
	else {
		int num = is_area(N, start_row, start_col);

		// 구역 판정이면
		if (num > not_area) {
			if (num == 1) one++;
			else if (num == 0) zero++;
			else m_one++;
		}
		// 구역 판정이 아니면 9등분 후 작은 영역으로 다시 판정
		else {
			for (int dy = 0; dy < N; dy += N / 3) {
				for (int dx = 0; dx < N; dx += N / 3) {
					paper_cnt(N / 3, start_row + dy, start_col + dx);
				}
			}
		}
	}

	return;
}

int main() {
	int N;
	cin >> N;
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			cin >> board[row][col];
		}
	}

	paper_cnt(N, 1, 1);

	cout << m_one << "\n" << zero << "\n" << one;

	return 0;
}