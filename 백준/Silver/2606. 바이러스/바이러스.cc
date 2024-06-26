#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define COMPUTER 101
bool visited[COMPUTER];
vector<int> graph[COMPUTER];

void BFS(const int& start) {
	queue<int> node;
	visited[start] = true;
	node.push(start);

	while (!node.empty()) {
		int u = node.front(), v, size = graph[u].size();
		for (int i = 0; i < size; i++) {
			v = graph[u][i];

			if (visited[v]) {
				continue;
			}

			visited[v] = true;
			node.push(v);
		}
		node.pop();
	}
}

int main() {
	int computerCNT, vertexCNT, u, v;
	cin >> computerCNT >> vertexCNT;

	while (vertexCNT--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	BFS(1);

	// 1번 점 제외 방문 노드 개수 세기
	int virusCNT = 0;
	for (int i = 2; i <= computerCNT; i++) {
		if (visited[i]) {
			virusCNT++;
		}
	}

	cout << virusCNT;

	return 0;
}