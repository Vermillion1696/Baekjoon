#include <iostream>
#include <unordered_map>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast_output;

    unordered_map<string, int> books;
    string key;
    int book_cnt;
    cin >> book_cnt;

    // 입력
    while (book_cnt--) {
        cin >> key;
        books[key]++;
    }

    int max = -1;
    for (auto& iter : books) {

        // 현재 최대보다 더 개수가 많으면
        if (max < iter.second) {
            key = iter.first;
            max = iter.second;
        }
        // 개수가 같으면 사전 순으로 앞서는 것을 저장
        else if (max == iter.second) {
            key = min(key, iter.first);
        }
    }

    cout << key;
}
