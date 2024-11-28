#include <iostream>
#include <queue>
#include <climits> // INT_MAX
#define fast_io cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
using pii = pair<int, int>;

int V_cnt, E_cnt;
int start_idx;

vector<int> dijkstra(const vector<vector<pii>>& graph) {
	
	int n = graph.size();
	vector<int> min_dis(n, INT_MAX); // 최단거리 배열 (리턴)
	min_dis[start_idx] = 0;

	// 우선순위 큐를 이용해 최소를 뽑음
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start_idx });

	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 이미 방문한 노드
		if (dis > min_dis[cur]) continue;

		// 인접 노드 확인
		for (const auto& E : graph[cur]) {
			int nxt = E.first;
			int wgt = E.second;

			// 더 짧은 경로면 업데이트
			if (min_dis[cur] + wgt < min_dis[nxt]) {
				min_dis[nxt] = min_dis[cur] + wgt;
				pq.push({ min_dis[nxt], nxt });
			}
		}
	}

	return min_dis;
}

int main() {
	fast_io;

	cin >> V_cnt >> E_cnt;
	cin >> start_idx;

	// graph[u].first : 도착점 (v)
	// graph[u].second : 가중치 (w)
	vector<vector<pii>> graph(V_cnt + 1);
	for (int i = 0; i < E_cnt; i++) {
		
		// u -> v, 가중치 w
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}

	vector<int> ans = dijkstra(graph);
	for (int i = 1; i < ans.size(); i++) {
		(ans[i] < INT_MAX ? cout << ans[i] << '\n' : cout << "INF\n");
	}

	return 0;
}