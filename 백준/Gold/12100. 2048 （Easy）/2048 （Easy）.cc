#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int max_block = -1;
constexpr int upside = 0;
constexpr int rightside = 1;
constexpr int downside = 2;
constexpr int leftside = 3;
constexpr int none = -1;

// 블록 클래스
class block {
public:
	void valueInput(int val);
	int valueOutput();
	
	// = 연산자 오버로딩
	block& operator=(const block& target) {
		if (this == &target) return *this;
		this->value = target.value;
		return *this;
	}
private:
	int value;
};

block orig_board[20][20];

// 블록 값 입력
void block::valueInput(int val) {
	block::value = val;
	return;
}

// 블록 값 출력
int block::valueOutput() {
	return block::value;
}

// dir 방향으로 curr_board 입력을 미는 함수
void push(int dir, block curr_board[20][20]) {
	for (int stat = 0; stat < N; stat++) {
		queue<int> q;
		int b4 = none;

		// dir 방향에 따라 vary 순회 위치, curr_board의 vary, stat 순서가 바뀐다
		if (dir == upside) {
			for (int vary = 0; vary < N; vary++) {
				int cur = curr_board[vary][stat].valueOutput();
				if (cur == 0) continue;

				if (cur == b4) {
					q.push(b4 * 2);
					b4 = none;
				}
				else if (b4 != none) {
					q.push(b4);
					b4 = cur;
				}
				else {
					b4 = cur;
				}
			}
			if (b4 != none) {
				q.push(b4);
			}
			for (int vary = 0; vary < N; vary++) {
				if (!q.empty()) {
					curr_board[vary][stat].valueInput(q.front());
					q.pop();
				}
				else {
					curr_board[vary][stat].valueInput(0);
				}
			}
		}
		else if (dir == rightside) {
			for (int vary = N - 1; vary >= 0; vary--) {
				int cur = curr_board[stat][vary].valueOutput();
				if (cur == 0) continue;

				if (cur == b4) {
					q.push(b4 * 2);
					b4 = none;
				}
				else if (b4 != none) {
					q.push(b4);
					b4 = cur;
				}
				else {
					b4 = cur;
				}
			}
			if (b4 != none) {
				q.push(b4);
			}
			for (int vary = N - 1; vary >= 0; vary--) {
				if (!q.empty()) {
					curr_board[stat][vary].valueInput(q.front());
					q.pop();
				}
				else {
					curr_board[stat][vary].valueInput(0);
				}
			}
		}
		else if (dir == downside) {
			for (int vary = N - 1; vary >= 0; vary--) {
				int cur = curr_board[vary][stat].valueOutput();
				if (cur == 0) continue;

				if (cur == b4) {
					q.push(b4 * 2);
					b4 = none;
				}
				else if (b4 != none) {
					q.push(b4);
					b4 = cur;
				}
				else {
					b4 = cur;
				}
			}
			if (b4 != none) {
				q.push(b4);
			}
			for (int vary = N - 1; vary >= 0; vary--) {
				if (!q.empty()) {
					curr_board[vary][stat].valueInput(q.front());
					q.pop();
				}
				else {
					curr_board[vary][stat].valueInput(0);
				}
			}
		}
		else if (dir == leftside) {
			for (int vary = 0; vary < N; vary++) {
				int cur = curr_board[stat][vary].valueOutput();
				if (cur == 0) continue;

				if (cur == b4) {
					q.push(b4 * 2);
					b4 = none;
				}
				else if (b4 != none) {
					q.push(b4);
					b4 = cur;
				}
				else {
					b4 = cur;
				}
			}
			if (b4 != none) {
				q.push(b4);
			}
			for (int vary = 0; vary < N; vary++) {
				if (!q.empty()) {
					curr_board[stat][vary].valueInput(q.front());
					q.pop();
				}
				else {
					curr_board[stat][vary].valueInput(0);
				}
			}
		}
	}
	return;
}

// 보드 복사 함수
// = 연산자 오버로딩 사용
void board_set(block lboard[20][20], const block rboard[20][20]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			lboard[y][x] = rboard[y][x];
		}
	}
	return;
}

// 백트래킹
void back_tracking(int times, block prev_board[20][20]) {
	block curr_board[20][20];
	board_set(curr_board, prev_board);

	// 탈출 조건 (5회)
	if (times == 5) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				max_block = max(max_block, curr_board[y][x].valueOutput());
			}
		}
	}
	else {

		// 1. curr_board를 밀기
		// 2. 백트래킹 재귀에 curr_board 넣고 들어가기
		// 3. (들어간 재귀에서의 prev_board) = (이전 재귀에서의 curr_board)
		// 4. 재귀를 끝내고 나와서 prev_board를 다시 curr_board에 복사 (curr_board 복구)

		push(upside, curr_board);
		back_tracking(times + 1, curr_board);
		board_set(curr_board, prev_board);

		push(rightside, curr_board);
		back_tracking(times + 1, curr_board);
		board_set(curr_board, prev_board);

		push(downside, curr_board);
		back_tracking(times + 1, curr_board);
		board_set(curr_board, prev_board);

		push(leftside, curr_board);
		back_tracking(times + 1, curr_board);
		board_set(curr_board, prev_board);
	}
	return;
}

int main() {
	cin >> N;
	int value;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> value;
			orig_board[y][x].valueInput(value);
		}
	}

	back_tracking(0, orig_board);

	cout << max_block;

	return 0;
}