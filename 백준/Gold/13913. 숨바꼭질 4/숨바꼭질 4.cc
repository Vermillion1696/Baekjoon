#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int subin, bro;
int map[MAX];
int prevPos[MAX];  // 이전 위치를 저장하는 배열

void BFS() {
    fill(map, map + MAX, -1);

    queue<int> q;
    map[subin] = 0;
    q.push(subin);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == bro) return;  // 동생을 찾으면 BFS 종료

        int next_positions[3] = { cur * 2, cur - 1, cur + 1 };

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];

            if (next < 0 || next >= MAX) continue;

            if (map[next] == -1 || map[next] > map[cur] + 1) {
                map[next] = map[cur] + 1;
                prevPos[next] = cur;  // next로 오기 전의 위치 기록
                q.push(next);
            }
        }
    }
}

void printPath(int bro) {
    vector<int> path;
    for (int at = bro; at != subin; at = prevPos[at]) {
        path.push_back(at);
    }
    path.push_back(subin);
    reverse(path.begin(), path.end());

    for (int pos : path) {
        cout << pos << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> subin >> bro;

    BFS();

    cout << map[bro] << "\n";
    printPath(bro);

    return 0;
}
