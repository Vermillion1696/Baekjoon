#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int board[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int rowMAX, columnMAX;

// 디버깅용 board 출력 함수
void boardPRINT(const int& row, const int& column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

int BFS(const int& row, const int& column, const int& group_number) {
	queue<pair<int, int>> q;
	board[row][column] = group_number;
	q.push({ column, row });
	int cnt = 1;

	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int cur_x = q.front().first + dx[dir];
			int cur_y = q.front().second + dy[dir];

			if (cur_x < 0 || cur_x >= columnMAX || cur_y < 0 || cur_y >= rowMAX) continue;
			if (board[cur_y][cur_x] != 0) continue;

			board[cur_y][cur_x] = group_number;
			q.push({ cur_x, cur_y });
			cnt++;
		}
		//boardPRINT(rowMAX, columnMAX);
		//cout << "\n";
		q.pop();
	}

	return cnt;
}

int main() {
	int rectangle;
	cin >> rowMAX >> columnMAX >> rectangle;

	// 방문 불가능 구역 판정
	pair<int, int> start, end;
	while (rectangle--) {
		cin >> start.first >> start.second >> end.first >> end.second;
		for (int i = start.second; i < end.second; i++) {
			for (int j = start.first; j < end.first; j++) {
				board[i][j] = -1;
			}
		}
		//boardPRINT(row, column);
	}

	// 모든 점 BFS 돌리기
	vector<int> v;
	int group = 1;
	for (int i = 0; i < rowMAX; i++) {
		for (int j = 0; j < columnMAX; j++) {
			if (board[i][j] == 0) {
				v.push_back(BFS(i, j, group));
				group++;
			}
		}
	}

	int size = v.size();
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}

	return 0;
}