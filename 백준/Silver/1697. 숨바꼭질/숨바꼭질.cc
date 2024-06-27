#include <iostream>
#include <queue>
using namespace std;
#define MAX 100002
int visited[MAX];
// 1차원 BFS 문제로 보면 된다.
// 단, queue에 넣을 때 q+1,q-1,2q를 한 번에 넣어야 함

void BFS(const int& subin) {
	queue<int> q;
	int current = 1;
	visited[subin] = current;
	q.push(subin);

	while (!q.empty()) {
		int set[3] = { q.front() + 1, q.front() - 1, q.front() * 2 };
		int current = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next = set[i];

			if (next < 0 || next > 100000) {
				continue;
			}
			if (visited[next] != MAX) {
				continue;
			}

			visited[next] = visited[current] + 1;
			q.push(set[i]);
		}
	}
}

int main() {
	fill(visited, visited + MAX, MAX);
	int subin, brother;
	cin >> subin >> brother;

	BFS(subin);

	cout << visited[brother] - 1;

	return 0;
}