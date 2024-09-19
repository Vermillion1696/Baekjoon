#include <iostream>
#include <vector>
#include <algorithm>
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// boards: 각 재귀 깊이에서의 보드 상태 저장
int N;
int max_block = 0;
int boards[11][20][20];

// from을 dir방향으로 민 값을 to에 저장하기
void push(int dir, int from[20][20], int to[20][20]) {
	
	if (dir == 0) { // 위쪽으로 이동
		for (int col = 0; col < N; col++) {
			int idx = 0;
			int last = 0;
			for (int row = 0; row < N; row++) {
				int val = from[row][col];
				if (val == 0) continue;
				if (last == 0) {
					last = val;
				}
				else if (last == val) {
					to[idx++][col] = last * 2;
					last = 0;
				}
				else {
					to[idx++][col] = last;
					last = val;
				}
			}
			if (last != 0) {
				to[idx++][col] = last;
			}
			for (; idx < N; idx++) {
				to[idx][col] = 0;
			}
		}
	}
	else if (dir == 1) { // 아래쪽으로 이동
		for (int col = 0; col < N; col++) {
			int idx = N - 1;
			int last = 0;
			for (int row = N - 1; row >= 0; row--) {
				int val = from[row][col];
				if (val == 0) continue;
				if (last == 0) {
					last = val;
				}
				else if (last == val) {
					to[idx--][col] = last * 2;
					last = 0;
				}
				else {
					to[idx--][col] = last;
					last = val;
				}
			}
			if (last != 0) {
				to[idx--][col] = last;
			}
			for (; idx >= 0; idx--) {
				to[idx][col] = 0;
			}
		}
	}
	else if (dir == 2) { // 왼쪽으로 이동
		for (int row = 0; row < N; row++) {
			int idx = 0;
			int last = 0;
			for (int col = 0; col < N; col++) {
				int val = from[row][col];
				if (val == 0) continue;
				if (last == 0) {
					last = val;
				}
				else if (last == val) {
					to[row][idx++] = last * 2;
					last = 0;
				}
				else {
					to[row][idx++] = last;
					last = val;
				}
			}
			if (last != 0) {
				to[row][idx++] = last;
			}
			for (; idx < N; idx++) {
				to[row][idx] = 0;
			}
		}
	}
	else if (dir == 3) { // 오른쪽으로 이동
		for (int row = 0; row < N; row++) {
			int idx = N - 1;
			int last = 0;
			for (int col = N - 1; col >= 0; col--) {
				int val = from[row][col];
				if (val == 0) continue;
				if (last == 0) {
					last = val;
				}
				else if (last == val) {
					to[row][idx--] = last * 2;
					last = 0;
				}
				else {
					to[row][idx--] = last;
					last = val;
				}
			}
			if (last != 0) {
				to[row][idx--] = last;
			}
			for (; idx >= 0; idx--) {
				to[row][idx] = 0;
			}
		}
	}
}

// 현재 보드에서 최대로 나올 수 있는 값 예측
int estimateMaxBlock(int board[20][20], int times_left) {
	vector<int> counts(21, 0); // 2^0 ~ 2^20

	// counts[n] : 2^n이 몇 개 있는지
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int val = board[y][x];
			if (val == 0) continue;
			int power = 0;
			while (val > 1) {
				val >>= 1;
				power++;
			}
			counts[power]++;
		}
	}

	// 합쳐질 수 있는건 다 합쳤다 가정한다
	int estimated_max = 0;
	for (int t = 0; t < times_left; t++) {
		for (int i = 20; i >= 0; i--) {
			if (counts[i] >= 2) {
				int merge_count = counts[i] / 2;
				counts[i] -= merge_count * 2;
				counts[i + 1] += merge_count;
			}
		}
	}

	// counts[i] > 0 이면 2^i 블럭이 있을 수 있다
	for (int i = 0; i <= 20; i++) {
		if (counts[i] > 0) {
			estimated_max = max(estimated_max, 1 << i);
		}
	}
	return estimated_max;
}

void backTracking(int times) {
	if (times == 10) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				max_block = max(max_block, boards[times][y][x]);
			}
		}
		return;
	}

	// 가지치기, 최대 블럭 <= 기존 최대면 진행 의미 X
	int estimated_max = estimateMaxBlock(boards[times], 10 - times);
	if (estimated_max <= max_block) {
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		// boards[times]에서 boards[times + 1]로 이동 적용
		// 변화가 있는지 확인
		bool changed = false;

		// boards[times + 1] 초기화
		for (int y = 0; y < N; y++) {
			fill(boards[times + 1][y], boards[times + 1][y] + N, 0);
		}

		push(dir, boards[times], boards[times + 1]);

		// 변화 확인
		for (int y = 0; y < N && !changed; y++) {
			for (int x = 0; x < N; x++) {
				if (boards[times + 1][y][x] != boards[times][y][x]) {
					changed = true;
					break;
				}
			}
		}

		// 변화가 있으면 백트래킹
		if (changed) {
			backTracking(times + 1);
		}
	}
}

int main() {
	fast_io;

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> boards[0][y][x];
		}
	}

	if (N == 1) {
		cout << boards[0][0][0];
		return 0;
	}

	backTracking(0);

	cout << max_block;

	return 0;
}