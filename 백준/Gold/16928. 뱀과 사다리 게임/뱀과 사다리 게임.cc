#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 101
#define from first
#define to second
using namespace std;
int board[MAX];
vector<pair<int, int>> warp;

void BFS() {

	fill(board, board + MAX, -1);

	// dir, gen
	queue<pair<int, int>> q;
	board[1] = 0;
	q.push({ 1, 0 });

	while (!q.empty()) {
		for (int dice = 1; dice <= 6; dice++) {
			int cur_dir = q.front().first + dice;
			int cur_gen = q.front().second;

			if (cur_dir <= 0 || cur_dir >= MAX) continue;

			// 뱀이나 사다리인 칸이면 이동 후 그 자리로 이동
			int warp_size = warp.size();
			for (int i = 0; i < warp_size; i++) {
				if (warp[i].from == cur_dir) {
					cur_dir = warp[i].to;
					break;
				}
			}

			if (board[cur_dir] == -1 || board[cur_dir] > cur_gen + 1) {
				board[cur_dir] = cur_gen + 1;
				q.push({ cur_dir, cur_gen + 1 });
			}
		}
		q.pop();
	}
}

int main() {
	int ladder, snake;
	cin >> ladder >> snake;
	
	pair<int, int> p;
	for (int i = 0; i < ladder + snake; i++) {
		cin >> p.from >> p.to;
		warp.push_back(p);
	}

	sort(warp.begin(), warp.end());
	BFS();

	cout << board[100];

	return 0;
}