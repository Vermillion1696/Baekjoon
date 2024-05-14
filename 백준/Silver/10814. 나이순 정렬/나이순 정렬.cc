#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// 구조체 선언, 나이, 이름, 가입 시간을 저장
typedef struct profile {
    int age;
    int time;
    string name;
} Profile;

// 최대 10만명이므로, 크기가 커지니까 main 외부에 선언
Profile boj[101010];

// 인자값 전달 방식 사용자 지정 선언
// 나이가 다르면 나이순 선정렬, 이후 가입순 정렬
bool compare(Profile a, Profile b) {
    if (a.age != b.age) {
        return a.age < b.age;
    }
    else {
        return a.time < b.time;
    }
}

int main()
{
    // 입력
    int n;
    cin >> n;
    int time = 0;
    for (int i = 0; i < n; i++) {
        cin >> boj[i].age;
        cin >> boj[i].name;
        boj[i].time = time;
        time++;
    }

    // 정렬
    sort(boj, boj + n, compare);

    // 출력
    for (int i = 0; i < n; i++) {
        cout << boj[i].age << " " << boj[i].name << "\n";
    }

    return 0;
}