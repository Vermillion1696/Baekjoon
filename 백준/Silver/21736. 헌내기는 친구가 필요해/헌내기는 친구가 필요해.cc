#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define MAX 601
#define X first
#define Y second
using namespace std;
int map[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row, col;
vector<pair<int, int>> p_point;
pair<int, int> person, start;

// 필드 입력 함수, 방문 불가 위치는 -1
void map_set() {
	char c;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> c;
			if (c == 'X') map[i][j] = -1;
			else if (c == 'P') {
				person.X = j;
				person.Y = i;
				p_point.push_back(person);
				map[i][j] = 0;
			}
			else if (c == 'I') {
				start.X = j;
				start.Y = i;
				map[i][j] = 0;
			}
			else map[i][j] = 0;
		}
	}

	return;
}

// BFS
void BFS() {
	queue<pair<int, int>> q;
	q.push(start);
	map[start.Y][start.X] = 1;

	while(!q.empty()){
		for (int dir = 0; dir < 4; dir++) {
			int cur_x = q.front().X + dx[dir];
			int cur_y = q.front().Y + dy[dir];
			
			if (cur_x < 1 || cur_x > col || cur_y < 1 || cur_y > row) continue;
			if (map[cur_y][cur_x] != 0) continue;

			map[cur_y][cur_x] = 1;
			q.push({ cur_x, cur_y });
		}
		q.pop();
	}

	return;
}

int main() {
	cin >> row >> col;
	map_set();

	BFS();

	int person_cnt = 0, v_size = p_point.size();
	for (int i = 0; i < v_size; i++) {
		if (map[p_point[i].Y][p_point[i].X] == 1) person_cnt++;
	}

	person_cnt > 0 ? cout << person_cnt : cout << "TT";

	return 0;
}