#include <iostream>
#include <queue>
#define fast_io cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
constexpr int MAX = 10000 + 1;
int vis[MAX];
int mov[MAX];
int br_size;

void BFS(int start) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    vis[start] = 0;

    while (!q.empty()) {
        int c_dir = q.front().first;
        int c_mov = q.front().second;
        q.pop();

        for (int mul : {1, -1}) { // 양방향 점프
            int next = c_dir;

            while (true) {
                next += mov[c_dir] * mul;
                if (next < 1 || next > br_size) break; // 범위 체크

                if (vis[next] == -1 || vis[next] > c_mov + 1) {
                    vis[next] = c_mov + 1;
                    q.push({ next, c_mov + 1 });
                }
            }
        }
    }
}

int main() {
    fill(vis, vis + MAX, -1);

    cin >> br_size;
    for (int i = 1; i <= br_size; i++) {
        cin >> mov[i];
    }

    int from, to;
    cin >> from >> to;

    BFS(from);

    cout << vis[to];

    return 0;
}