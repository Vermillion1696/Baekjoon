#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int subin, bro;
int map[MAX];

void BFS() {
    fill(map, map + MAX, -1);

    queue<int> q;
    map[subin] = 0;
    q.push(subin);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next_positions[3] = { cur * 2, cur - 1, cur + 1 };

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];

            if (next < 0 || next >= MAX) continue;

            // +-1 일땐 (다음 시간) = (현재 시간 + 1), *2 일땐 (다음 시간) = (현재 시간)
            int adj;
            i == 0 ? adj = 0 : adj = 1;

            if (map[next] == -1 || (map[next] != -1 && map[next] > map[cur] + 1)) {
                map[next] = map[cur] + adj;
                q.push(next);
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> subin >> bro;

    BFS();

    cout << map[bro];

    return 0;
}
