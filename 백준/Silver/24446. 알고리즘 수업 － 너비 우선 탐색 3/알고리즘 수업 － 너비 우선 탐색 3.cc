#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define nodeMAX 100001

// vector<int> graph[~]로 정점 n에 대해 (graph[n])
// 다음으로 연결되는 간선 표시 (graph[n][i] : n ~ graph[n][i] 연결 간선)
vector<int> graph[nodeMAX];
int visited[nodeMAX];

void BFS(const int& start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		// graph[n][i]
		// i가 0 ~ graph[n].size()-1까지 돌아야 함 (출발점 고정인 간선 개수)
		int size = graph[current].size();
		for (int i = 0; i < size; i++) {
			int next = graph[current][i];
			
			// 방문했던 곳이면 continue;
			if (visited[next] != 0) {
				continue;
			}

			// 아니면 방문 표시 후 queue에 push
			// 이전 깊이 + 1 = 현재 깊이
			visited[next] = visited[current] + 1;
			q.push(next);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int nodeCNT, vertexCNT, start;
	cin >> nodeCNT >> vertexCNT >> start;

	// a -> b, b -> a 추가 (undirected graph)
	int a, b;
	while (vertexCNT--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 각 i 하부 배열 정렬
	for (int i = 0; i <= nodeCNT; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	/*
	for (int i = 0; i < nodeCNT; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	BFS(start);

	for (int i = 1; i <= nodeCNT; i++) {
		if (i == start) {
			cout << 0 << "\n";
		}
		else if (visited[i] != 0) {
			cout << visited[i] << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}

	return 0;
}