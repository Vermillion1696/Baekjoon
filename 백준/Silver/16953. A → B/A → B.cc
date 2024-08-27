#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
ll a, b;
ll min_cnt = 1000000000;

void BFS() {

	// value, count
	queue<pair<ll, ll>> q;
	q.push({ a, 0 });

	// BFS는 최단경로가 가장 빨리 front에 도달한다는 보장 X
	// -> 모든 경로 확인
	while (!q.empty()) {

		// 현재 값이 b이면(도착) 이전 최소와 값 비교
		if (q.front().first == b) {
			min_cnt = min(q.front().second, min_cnt);
			q.pop();
		}
		else {
			// 뒤에 1 추가 -> 10배 + 1
			ll next_dir[2] = { q.front().first * 10 + 1, q.front().first * 2 };
			ll next_gen = q.front().second + 1;
			q.pop();

			for (int i = 0; i < 2; i++) {
				ll next_val = next_dir[i];

				if (next_val > 1000000000 || next_val < 1) continue;

				q.push({ next_val, next_gen });
			}
		}
	}

	return;
}


int main() {
	cin >> a >> b;

	BFS();

	if (min_cnt == 1000000000) cout << -1;
	else cout << min_cnt + 1;

	return 0;
}