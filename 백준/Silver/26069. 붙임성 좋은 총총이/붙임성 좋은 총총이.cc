#include <iostream>
#include <unordered_set>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast_output;

    // 무 지 개 댄 스 를 추고 있는 사람의 집합
    unordered_set<string> dancing = { "ChongChong" };
    string from, to;
    int command_cnt;
    cin >> command_cnt;

    while (command_cnt--) {
        cin >> from >> to;

        auto iter = dancing.find(from);
        
        // from이 없음
        if (iter == dancing.end()) {
            iter = dancing.find(to);

            // to도 없으면 건너뛰기
            if (iter == dancing.end()) continue;
            // to가 있으면 from <-> to 바꾸기
            else swap(from, to);
        }
        // from이 있음
        else {
            iter = dancing.find(to);
            
            // to가 있으면 건너뛰기
            if (iter != dancing.end()) continue;
        }

        dancing.insert(to);
    }

    cout << dancing.size();

    return 0;
}