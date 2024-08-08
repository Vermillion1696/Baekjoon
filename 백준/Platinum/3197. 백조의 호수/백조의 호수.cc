#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>
#define MAX 1501
using namespace std;

bool map[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row, column;
vector<pair<int, int>> bird_point;
queue<pair<int, int>> water_queue, next_water_queue;

// 1 : 얼음
// 0 : 물
void map_set() {
    char c;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            cin >> c;

            switch (c) {
            case 'X':
                map[i][j] = 1;
                break;
            case 'L':
                bird_point.push_back({ j,i });
                map[i][j] = 0;
                water_queue.push({ j,i });
                break;
            default:
                map[i][j] = 0;
                water_queue.push({ j, i });
            }
        }
    }
}

void map_BFS() {
    while (!water_queue.empty()) {
        int x = water_queue.front().first;
        int y = water_queue.front().second;
        water_queue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || nx > column || ny < 1 || ny > row) continue;
            if (map[ny][nx] == 1) {
                map[ny][nx] = 0;
                next_water_queue.push({ nx, ny });
            }
        }
    }
    swap(water_queue, next_water_queue);
}

int bird_BFS() {
    queue<pair<int, int>> bq;
    vector<vector<bool>> visited(row + 1, vector<bool>(column + 1, false));

    bq.push(bird_point[0]);
    visited[bird_point[0].second][bird_point[0].first] = true;

    int day = 0;
    while (true) {
        queue<pair<int, int>> next_bq;
        while (!bq.empty()) {
            int x = bq.front().first;
            int y = bq.front().second;
            bq.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 1 || nx > column || ny < 1 || ny > row || visited[ny][nx]) continue;

                if (nx == bird_point[1].first && ny == bird_point[1].second) {
                    return day;
                }

                visited[ny][nx] = true;
                if (map[ny][nx] == 0) {
                    bq.push({ nx, ny });
                }
                else {
                    next_bq.push({ nx, ny });
                }
            }
        }

        map_BFS();
        day++;
        swap(bq, next_bq);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> row >> column;

    map_set();
    int day = bird_BFS();

    cout << day;

    return 0;
}
