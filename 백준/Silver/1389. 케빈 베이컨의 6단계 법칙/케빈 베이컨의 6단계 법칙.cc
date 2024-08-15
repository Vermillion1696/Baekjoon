#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 101
#define INF 1e9 // 무한대 값 (이론상 충분히 큰 값)
using namespace std;
int graph[MAX][MAX];

int main() {
    int N, M;
    cin >> N >> M;

    // graph 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    int from, to;
    for (int i = 1; i <= M; i++) {
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 케빈 베이컨 수 계산
    int min_num = INF, min_index = 1;
    for (int i = 1; i <= N; i++) {
        int num = 0;
        for (int j = 1; j <= N; j++) {
            num += graph[i][j];
        }

        if (min_num > num) {
            min_num = num;
            min_index = i;
        }
    }

    cout << min_index;

    return 0;
}