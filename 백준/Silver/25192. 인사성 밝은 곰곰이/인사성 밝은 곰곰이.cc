#include <iostream>
#include <unordered_set>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast_output;

    // 곰곰티콘을 이미 쓴 멤버를 저장할 집합
    unordered_set<string> member;
    string str;
    int command_cnt, gomgom = 0;
    cin >> command_cnt;

    while (command_cnt--) {
        cin >> str;

        // 엔터가 들어오면 모든 멤버가 다시 곰곰티콘을 쓸 수 있음
        if (str == "ENTER") {
            member.clear();
        }
        else {
            auto iter = member.find(str);
            
            // 현재 문자열이 새 사람이면 횟수 + 1, 곰곰티콘을 못 쓰는 사람 집합에 추가
            if (iter == member.end()) {
                member.insert(str);
                gomgom++;
            }
        }
    }

    cout << gomgom;

    return 0;
}
