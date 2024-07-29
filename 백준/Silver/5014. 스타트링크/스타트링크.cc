#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;
int board[MAX];
int range;

void BFS(const int& start, const int& up, const int& down) {
	queue<pair<int, int>> q;
	int generation = 0;
	board[start] = generation;
	q.push({ start, generation + 1 });

	while (!q.empty()) {
		int upper = q.front().first + up;
		int lower = q.front().first - down;

		if (upper >= 1 && upper <= range && board[upper] == -1) {
			q.push({ upper, q.front().second + 1});
			board[upper] = q.front().second;
		}
		if (lower >= 1 && lower <= range && board[lower] == -1) {
			q.push({ lower, q.front().second + 1});
			board[lower] = q.front().second;
		}

		q.pop();
	}
}

int main() {
	int start, target, up, down;
	cin >> range >> start >> target >> up >> down;

	fill(board, board + MAX, -1);
	
	BFS(start, up, down);

	/*
	for (int i = 1; i <= range; i++) {
		cout << board[i] << " ";
		if (i % 10 == 0) cout << "\n";
	}
	*/

	if (target >= 1 && target <= range && board[target] != -1) {
		cout << board[target];
	}
	else {
		cout << "use the stairs";
	}

	return 0;
}