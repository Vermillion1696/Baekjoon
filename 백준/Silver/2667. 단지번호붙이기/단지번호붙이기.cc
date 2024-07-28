#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// 1 ~ 25까지 쓰게 만듦
#define MAX 26
int map[MAX][MAX] = {};
vector<int> v;

int BFS(const int& row, const int& column, const int& number) {
	queue<pair<int, int>> q;
	int cnt = 1;
	map[row][column] = number;
	q.push({ column, row });

	while (!q.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = q.front().first + dx[dir];
			int ny = q.front().second + dy[dir];

			if (nx <= 0 || nx > 25 || ny <= 0 || ny > 25) continue;
			if (map[ny][nx] != 1) continue;

			map[ny][nx] = number;
			q.push({ nx, ny });
			cnt++;
		}
		q.pop();
	}

	return cnt;
}

int main() {
	int n;
	char c;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	// 0 : 방문 불가
	// 1 : 미방문
	// 2+ : 단지 번호
	int number = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) v.push_back(BFS(i, j, number));
		}
	}

	int size = v.size();
	sort(v.begin(), v.end());
	
	cout << size << "\n";
	for (int i = 0; i < size; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}