// 배우는 중입니다...
// 참고 영상: https://youtu.be/jZwf4OPlhtk?si=V0Nt-6EG7umuAiQS

// 1. BFS등 완탐에서 배열 범위 밖 조건을 OOB 함수로 빼는 방법도 있음 (유의미한 시간차인지는 모름?)
// 2. 재귀 -> 4진법으로 바꾸는 테크닉
#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
constexpr int wall = 6;
constexpr int watch = 7;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

// ori_board -> 원본 맵
// res_board -> 비교 맵
int ori_board[10][10];
int res_board[10][10];
vector<pair<int, int>> cctv;

// Out Of Bounds, 값이 범위 밖을 벗어났는지 확인하는 함수
bool OOB(int a, int b) {
	return a < 0 || a >= n || b < 0 || b >= m;
}

// dir 방향에 따른 보드 칠하기
// dir % 4 == 0 -> x++, right
// dir % 4 == 1 -> y++, down
// dir % 4 == 2 -> x--, left
// dir % 4 == 3 -> y--, up
void fill_board(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];

		// 맵 밖으로 나가거나 벽이면 종료
		if (OOB(x, y) || res_board[x][y] == wall) return;

		// 현재 칸이 cctv면 continue
		if (res_board[x][y] != 0) continue;
		res_board[x][y] = watch;
	}
}

int main() {
	fast_io;
	
	cin >> n >> m;
	int min_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ori_board[i][j];

			// cctv면 입력
			if (ori_board[i][j] != 0 && ori_board[i][j] != 6) {
				cctv.push_back({ i,j });
			}

			// cctv가 적어도 한 개 보장이 아니므로 min_area를 원본 맵의 0 개수로 세팅
			if (ori_board[i][j] == 0) min_area++;
		}
	}

	// 4진법으로 각 cctv의 감시 방향을 저장
	// 0 -> right, 1 -> down, 2 -> left, 3 -> up
	// ex. 210 : (왼쪽, 아래, 오른쪽) 보고 있음, cctv 총 3개
	for (int how = 0; how < (1 << (2 * cctv.size())); how++) {

		// 맵 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res_board[i][j] = ori_board[i][j];
			}
		}

		int cur = how;
		for (int i = 0; i < cctv.size(); i++) {

			// 방향 == 그 자릿수
			int dir = cur % 4;
			cur /= 4;

			int x = cctv[i].X;
			int y = cctv[i].Y;

			if (ori_board[x][y] == 1) {
				fill_board(x, y, dir);
			}
			else if (ori_board[x][y] == 2) {
				fill_board(x, y, dir);
				fill_board(x, y, dir + 2);
			}
			else if (ori_board[x][y] == 3) {
				fill_board(x, y, dir);
				fill_board(x, y, dir + 1);
			}
			else if (ori_board[x][y] == 4) {
				for (int add = 0; add < 3; add++) {
					fill_board(x, y, dir + add);
				}
			}
			else {
				for (int add = 0; add < 4; add++) {
					fill_board(x, y, dir + add);
				}
			}
		}

		// 0 개수 카운트
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				val += (res_board[i][j] == 0);
			}
		}
		min_area = min(min_area, val);
	}

	cout << min_area;

	return 0;
}