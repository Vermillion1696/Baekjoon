#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// CCW 함수
bool CCW(int a, int b, int c) {
    return (a * c) * sqrt(2) <= b * (a + c);
}

// 팩토리얼 함수
long long int factorial(int n) {
    long long int total = 1;
    for (int i = 1; i <= n; i++) {
        total *= i;
    }
    return total;
}

int main() {

    int total = 1;

    // 입력
    int num[8];
    for (int i = 0; i < 8; i++) {
        cin >> num[i];
    }

    // 정렬
    sort(num, num + 8);

    // 중복 숫자 체크
    vector<pair<int, int>> v;
    v.push_back(make_pair(num[0], 1));

    // 다르면 vector에 (num, count) 넣기
    // 같으면 vector.second()의 값 ++;
    bool exist;
    for (int i = 1; i <= 7; i++) {
        exist = 0;

        // 벡터 전부 검사 후 있으면 개수 ++
        for (int j = 0; j < v.size(); j++) {
            if (num[i] == v[j].first) {
                v[j].second++;
                exist = 1;
            }
        }

        // 없으면 넣기
        if (!exist) {
            v.push_back(make_pair(num[i], 1));
        }
    }

    // next_permutation이 있는 동안 돌기
    // 주의 ! next_permutation은 중복 제외 순열만 반환 !!
    int cnt = 0;
    do {
        // 가능 불가능 판별 tf
        bool tf = 1;

        // 012 123 234 ... 567 670 701 까지 전부 만족시 cnt++
        for (int i = 0; i < 8; i++) {
            if (!CCW(num[i], num[(i + 1) % 8], num[(i + 2) % 8])) {
                tf = 0;
                break;
            }
        }

        if (tf) {
            cnt++;
        }

    } while (next_permutation(num, num + 8));

    // 디버깅용 코드
    /*
    for (int i = 0; i < v.size(); i++) {
        cout << "(" << v[i].first << ", " << v[i].second << ")" << "\n";
    }
    cout << cnt << "\n";
    */

    // 보정값
    while (!v.empty()) {
        cnt *= factorial(v.back().second);
        v.pop_back();
    }

    cout << cnt;

    return 0;
}