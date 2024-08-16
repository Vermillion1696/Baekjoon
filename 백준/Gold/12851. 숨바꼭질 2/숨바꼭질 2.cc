#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int subin, bro;
int map[MAX];
int way[MAX];

void BFS() {
    fill(map, map + MAX, -1);

    queue<int> q;
    map[subin] = 0;
    way[subin] = 1;
    q.push(subin);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next_positions[3] = { cur - 1, cur + 1, cur * 2 };

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];

            if (next < 0 || next >= MAX) continue;

            if (map[next] == -1) {  // 미방문
                map[next] = map[cur] + 1;
                way[next] = way[cur];
                q.push(next);
            }
            else if (map[next] == map[cur] + 1) {  // 같은 시간에 도착하는 다른 방법 존재
                way[next] += way[cur];
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

    cout << map[bro] << "\n" << way[bro];

    return 0;
}
