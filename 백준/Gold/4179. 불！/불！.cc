#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

#define Y first
#define X second
#define MAX 1001

// 0 : 길
// 1 : 지훈 (또는 지나온 길)
// 2 : 벽
// 3 : 불
int map[MAX][MAX];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

// 디버깅용 맵 출력 함수
void mapPrint(const int& column, const int& row) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int BFS(const int& column, const int& row) {

    // 시작점 찾기
    queue<pair<int, int>> fireSTART;
    pair<int, int> JihunSTART;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            if (map[i][j] == 3) {
                fireSTART.push({ i,j });
            }
            else if (map[i][j] == 1) {
                JihunSTART = { i,j };
            }
        }
    }

    int time = 0;
    queue<tuple<int, int, int>> QJ;
    queue<tuple<int, int, int>> QF;
    QJ.push(make_tuple(JihunSTART.Y, JihunSTART.X, time));
    while (!fireSTART.empty()) {
        QF.push(make_tuple(fireSTART.front().Y, fireSTART.front().X, time));
        fireSTART.pop();
    }

    while (!QJ.empty() || !QF.empty()) {
        time++;

        // 불이 먼저 번진다
        int fireSize = QF.size();
        while (fireSize--) {
            int fy, fx, ft;
            tie(fy, fx, ft) = QF.front();
            QF.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = fy + dy[dir];
                int nx = fx + dx[dir];

                if (nx <= 0 || nx > column || ny <= 0 || ny > row) {
                    continue;
                }
                if (map[ny][nx] == 0 || map[ny][nx] == 1) {
                    map[ny][nx] = 3;
                    QF.push(make_tuple(ny, nx, time));
                }
            }
        }

        // 지훈이 이동한다
        int jihunSize = QJ.size();
        while (jihunSize--) {
            int jy, jx, jt;
            tie(jy, jx, jt) = QJ.front();
            QJ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = jy + dy[dir];
                int nx = jx + dx[dir];

                if (nx <= 0 || nx > column || ny <= 0 || ny > row) {
                    // 지훈이 맵의 가장자리에 도착하면 탈출
                    return time;
                }
                if (map[ny][nx] == 0) {
                    map[ny][nx] = 1;
                    QJ.push(make_tuple(ny, nx, time));
                }
            }
        }

        // 지훈의 위치가 가장자리에 있는지 다시 검사
        for (int i = 1; i <= column; i++) {
            if (map[1][i] == 1 || map[row][i] == 1) {
                return time + 1;
            }
        }
        for (int i = 1; i <= row; i++) {
            if (map[i][1] == 1 || map[i][column] == 1) {
                return time + 1;
            }
        }

        // 탈출 조건 검사
        // 패배 조건 : 지훈(1)이 어느 곳에도 없음
        bool available = false;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                if (map[i][j] == 1) {
                    available = true;
                    goto forOUT;
                }
            }
        }
    forOUT:
        if (!available) {
            return -1;
        }
    }

    // 탈출 조건을 못 타고 while문을 나가면 불가능이다
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int column, row;
    cin >> row >> column;

    char c;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            cin >> c;
            if (c == '#') {
                map[i][j] = 2;
            }
            else if (c == 'F') {
                map[i][j] = 3;
            }
            else if (c == '.') {
                map[i][j] = 0;
            }
            else {
                map[i][j] = 1;
            }
        }
    }

    int time = BFS(column, row);

    time > 0 ? cout << time : cout << "IMPOSSIBLE";

    return 0;
}
