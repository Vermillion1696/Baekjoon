#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1001

using namespace std;

int map[MAX][MAX];
int dis[2][MAX][MAX];  // dis[0]은 벽을 부수지 않은 경우, dis[1]은 벽을 부순 경우
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int row, column;

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
    for (int k = 0; k < 2; k++) {
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

    // x, y, isBreak
    queue<tuple<int, int, bool>> q;
    q.push({ 1, 1, false });
    dis[0][1][1] = 1;

    while (!q.empty()) {
        int cur_x, cur_y;
        bool isBreak;
        tie(cur_x, cur_y, isBreak) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nx < 1 || nx > column || ny < 1 || ny > row) continue;

            // 벽이 아닌 경우
            if (map[ny][nx] == 0) {

                // 미방문 또는 (적힌 값) > (현재 값) + 1 인 경우에 큐에 넣기
                if (dis[isBreak][ny][nx] == 0 || dis[isBreak][ny][nx] > dis[isBreak][cur_y][cur_x] + 1) {
                    dis[isBreak][ny][nx] = dis[isBreak][cur_y][cur_x] + 1;
                    q.push({ nx, ny, isBreak });
                }
            }
            // 벽인 경우
            else {

                // 벽을 부순 적이 없고, (적힌 값) > (현재 값) + 1 인 경우에 큐에 넣기
                if (!isBreak && (dis[1][ny][nx] == 0 || dis[1][ny][nx] > dis[0][cur_y][cur_x] + 1)) {
                    dis[1][ny][nx] = dis[0][cur_y][cur_x] + 1;
                    q.push({ nx, ny, true });
                }
            }
        }
    }
    return;
}

int main() {
    cin >> row >> column;
    map_set();
    BFS_break_wall();

    int result;
    if (dis[0][row][column] != 0 && dis[1][row][column] != 0) result = min(dis[0][row][column], dis[1][row][column]);
    else if (dis[0][row][column] == 0 && dis[1][row][column] != 0) result = dis[1][row][column];
    else if (dis[0][row][column] != 0 && dis[1][row][column] == 0) result = dis[0][row][column];
    else result = -1;

    cout << result;

    return 0;
}
