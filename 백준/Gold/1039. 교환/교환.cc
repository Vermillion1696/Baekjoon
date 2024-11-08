#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define fast_io cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
constexpr int MAX = 1000000 + 1;

// vis[i][0]: k가 짝수일 때 i 방문 여부
// vis[i][1]: k가 홀수일 때 i 방문 여부
bool vis[MAX][2];

void BFS(string str, int k) {
	queue<pair<string, int>> q;
	q.push({ str, 0 });

	while (!q.empty()) {
		string cur_s = q.front().first;
		int cur_d = q.front().second;
		q.pop();

		if (cur_d == k) continue;

		int s_size = cur_s.size();
		for (int i = 0; i < s_size; i++) {
			for (int j = i + 1; j < s_size; j++) {
				string new_s = cur_s;
				swap(new_s[i], new_s[j]);

				if (new_s[0] == '0') continue;

				int num = stoi(new_s);
				int next_d = cur_d + 1;

				if (!vis[num][next_d % 2]) {
					vis[num][next_d % 2] = true;
					q.push({ new_s, next_d });
				}
			}
		}
	}
}

int main() {
	fast_io;

	string str;
	int k;
	cin >> str >> k;

	BFS(str, k);
	int max_value = -1;

	for (int i = 1; i < MAX; i++) {
		if (vis[i][k % 2]) max_value = i;
	}

	cout << max_value;

	return 0;
}
