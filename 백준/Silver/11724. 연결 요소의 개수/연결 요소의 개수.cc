#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
int group[1001];
int node_cnt, vertex_cnt;

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

void BFS(const int& start, const int& group_num) {

	queue<int> q;
	q.push(start);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (group[cur] != 0) continue;

		group[cur] = group_num;
		
		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			q.push(graph[cur][i]);
		}
	}

	return;
}

int main() {
	cin >> node_cnt >> vertex_cnt;

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

	// 그룹 번호를 1번부터 붙임
	// 번호가 안 붙어 있는 칸은 아직까지 BFS로 도달하지 못 한 칸 (새 그룹)
	int group_num = 0;
	for (int i = 1; i <= node_cnt; i++) {
		if (group[i] == 0) {
			group_num++;
			BFS(i, group_num);
		}
	}

	cout << group_num;

	return 0;
}