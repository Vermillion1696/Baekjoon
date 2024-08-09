#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool vis[10000];
int from[10000];
char how[10000];

string DSLR(int start, int target) {
    fill(vis, vis + 10000, 0);

    queue<int> q;
    q.push(start);
    vis[start] = true;
    from[start] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) {
            string result = "";
            while (cur != start) {
                result += how[cur];
                cur = from[cur];
            }
            reverse(result.begin(), result.end());
            return result;
        }

        // D operation
        int next = (2 * cur) % 10000;
        if (!vis[next]) {
            q.push(next);
            vis[next] = true;
            from[next] = cur;
            how[next] = 'D';
        }

        // S operation
        next = (cur == 0) ? 9999 : cur - 1;
        if (!vis[next]) {
            q.push(next);
            vis[next] = true;
            from[next] = cur;
            how[next] = 'S';
        }

        // L operation
        next = (cur % 1000) * 10 + cur / 1000;
        if (!vis[next]) {
            q.push(next);
            vis[next] = true;
            from[next] = cur;
            how[next] = 'L';
        }

        // R operation
        next = (cur % 10) * 1000 + cur / 10;
        if (!vis[next]) {
            q.push(next);
            vis[next] = true;
            from[next] = cur;
            how[next] = 'R';
        }
    }
    return "";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int start, target;
        cin >> start >> target;
        cout << DSLR(start, target) << "\n";
    }

    return 0;
}