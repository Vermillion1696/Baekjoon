#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1001

using namespace std;

int map[MAX][MAX];
int dis[11][MAX][MAX];  // dis[0]은 벽을 부수지 않은 경우, dis[n]은 n번 벽을 부순 경우
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int row, column, max_break;

// 맵 세팅 함수
void map_set() {
    char c;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    return;
}

// 디버깅용 거리 출력 함수
void dis_print() {
    for (int k = 0; k <= 10; k++) {
        cout << "dis[" << k << "]:\n";
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                cout << dis[k][i][j] << " ";
            }
            cout << "\n";
        }
    }
    return;
}

void BFS_break_wall() {

    // x, y, break_cnt
    queue<tuple<int, int, int>> q;
    q.push({ 1, 1, 0 });
    dis[0][1][1] = 1;

    while (!q.empty()) {
        int cur_x, cur_y, break_cnt;
        tie(cur_x, cur_y, break_cnt) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nx < 1 || nx > column || ny < 1 || ny > row) continue;

            // 벽이 아닌 경우
            if (map[ny][nx] == 0) {

                // 미방문 또는 (적힌 값) > (현재 값) + 1 인 경우에 큐에 넣기
                if (dis[break_cnt][ny][nx] == 0 || dis[break_cnt][ny][nx] > dis[break_cnt][cur_y][cur_x] + 1) {
                    dis[break_cnt][ny][nx] = dis[break_cnt][cur_y][cur_x] + 1;
                    q.push({ nx, ny, break_cnt });
                }
            }
            // 벽인 경우
            else {

                // 벽을 부순 횟수가 최대가 아니고, (적힌 값) > (현재 값) + 1 인 경우에 큐에 넣기
                if (break_cnt < max_break && (dis[break_cnt + 1][ny][nx] == 0 || dis[break_cnt + 1][ny][nx] > dis[break_cnt][cur_y][cur_x] + 1)) {
                    dis[break_cnt + 1][ny][nx] = dis[break_cnt][cur_y][cur_x] + 1;
                    q.push({ nx, ny, break_cnt + 1 });
                }
            }
        }
    }
    return;
}

int main() {
    cin >> row >> column >> max_break;
    map_set();
    BFS_break_wall();
    //dis_print();

    int min_dist = 1234567;
    for (int i = 0; i <= 10; i++) {
        if (dis[i][row][column] == 0) continue;
        min_dist = min(min_dist, dis[i][row][column]);
    }

    min_dist != 1234567 ? cout << min_dist : cout << -1;

    return 0;
}
