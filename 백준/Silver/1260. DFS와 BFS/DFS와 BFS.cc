#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
bool vis[1001];

// 디버깅용 그래프 출력 함수
void graph_print() {
	int vv_size = graph.size();
	int v_size;
	
	for (int i = 0; i < vv_size; i++) {
		v_size = graph[i].size();
		for (int j = 0; j < v_size; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
	return;
}

void BFS(const int& start) {

	fill(vis, vis + 1001, 0);

	queue<int> q;
	q.push(start);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (vis[cur]) continue;

		cout << cur << " ";
		vis[cur] = true;
		
		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			q.push(graph[cur][i]);
		}
	}

	cout << "\n";

	return;
}

void DFS(const int& start) {

	fill(vis, vis + 1001, 0);

	stack<int> s;
	s.push(start);

	while (!s.empty()) {

		int cur = s.top();
		s.pop();

		if (vis[cur]) continue;

		cout << cur << " ";
		vis[cur] = true;

		// 방문 가능한 노드가 많을 땐 작은 순서대로 방문한다는 조건 :
		// 스택은 FILO이므로, 큰 순서대로 넣어야 작은 순서대로 방문 함
		int size = graph[cur].size();
		for (int i = size - 1; i >= 0; i--) {
			s.push(graph[cur][i]);
		}
	}

	cout << "\n";

	return;
}

int main() {
	int node_cnt, vertex_cnt, start_index;
	cin >> node_cnt >> vertex_cnt >> start_index;

	// 노드 개수 + 1 만큼 벡터 만듦 (인덱싱 편하게 하기 위함) 
	for (int i = 0; i <= node_cnt; i++) {
		vector<int> v;
		graph.push_back(v);
	}

	// 간선 개수만큼 입력 받음
	pair<int, int> vertex;
	for (int i = 0; i < vertex_cnt; i++) {
		cin >> vertex.first >> vertex.second;
		graph[vertex.first].push_back(vertex.second);
		graph[vertex.second].push_back(vertex.first);
	}

	// 오름차순으로 정렬
	for (int i = 1; i <= node_cnt; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	DFS(start_index);
	BFS(start_index);

	return 0;
}