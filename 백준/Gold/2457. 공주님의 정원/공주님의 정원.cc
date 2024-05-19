#include <iostream>
#include <algorithm>
using namespace std;

// 구조체 선언
typedef struct Date {
    int start_month;
    int start_day;
    int end_month;
    int end_day;
} Date;
Date flowers[100000];

// <algorithm> 내장 sort() 인자 compare()
bool compare(const Date& a, const Date& b) {
    // 정렬 기준 1. 피는 달 빠름
    if (a.start_month != b.start_month) {
        return a.start_month < b.start_month;
    }
    // 정렬 기준 2. 피는 일 빠름
    if (a.start_day != b.start_day) {
        return a.start_day < b.start_day;
    }
    // 정렬 기준 3. 지는 달 느림
    if (a.end_month != b.end_month) {
        return a.end_month > b.end_month;
    }
    // 정렬 기준 4. 지는 일 느림
    return a.end_day > b.end_day;
}

// 초기 세팅
bool startingpoint(Date& a, int month, int day) {
    // 입력 데이터 Date a의 시작 시간이 3월 2일 이전인 경우
    if (a.start_month < 3 || (a.start_month == 3 && a.start_day <= 1)) {
        // 입력 데이터 Date a의 끝 시간이 result 시간보다 더 뒤에 있는 경우 return 1;
        if (a.end_month > month || (a.end_month == month && a.end_day > day)) {
            return true;
        }
    }
    return false;
}

// Date a 내부 start가 주어진 month-day보다 빠른지 아닌지 판별
bool startDateCompare(Date& a, int month, int day) {
    if (a.start_month < month) {
        return true;
    }
    if (a.start_month == month) {
        return a.start_day <= day;
    }
    return false;
}

// Date a 내부 end가 주어진 month-day보다 느린지 아닌지 판별
bool endDateCompare(Date& a, int month, int day) {
    if (a.end_month > month) {
        return true;
    }
    if (a.end_month == month) {
        return a.end_day > day;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flowers[i].start_month >> flowers[i].start_day >> flowers[i].end_month >> flowers[i].end_day;
    }

    // 정렬
    sort(flowers, flowers + n, compare);

    bool tf = true;
    int index = 0;
    int result_month = -1;
    int result_day = -1;
    int flower_count = 0;

    // 스타팅 포인트 찾기 (조건문 내부 : 시작 날짜가 <= 3.1인 것들 검사)
    while (index < n && (flowers[index].start_month < 3 || (flowers[index].start_month == 3 && flowers[index].start_day <= 1))) {
        if (startingpoint(flowers[index], result_month, result_day)) {
            result_month = flowers[index].end_month;
            result_day = flowers[index].end_day;
        }
        index++;
    }

    // 스타팅 포인트를 못 찾았으면 불가능 판정 후 종료
    if (result_month == -1) {
        tf = false;
    }
    else {
        flower_count++;
    }

    // 꽃의 범위를 11월 30일까지 채우는 과정
    while (tf && result_month < 12) {
        // result 뒤를 이을 꽃의 날짜 저장
        int max_month = -1;
        int max_day = -1;
        bool found = false;

        // result 이후부터 검사
        for (int i = index; i < n; i++) {
            // max가 result보단 빨리 피고 max보다 늦게 지면 max에 저장
            // for문을 탈출 할 때는 result보다 빨리 피는 꽃들중 가장 늦게 지는 꽃을 고르게 된다
            if (startDateCompare(flowers[i], result_month, result_day)) {
                if (endDateCompare(flowers[i], max_month, max_day)) {
                    max_month = flowers[i].end_month;
                    max_day = flowers[i].end_day;
                    found = true;
                }
            }
            // 정렬이 되어 있으므로 if문에 들어가지 못 한 case들은 모두 result보다 늦게 피는 꽃
            else {
                break;
            }
        }

        // 이을 꽃이 있으면 이를 result에 저장하고 개수 증가
        if (found) {
            result_month = max_month;
            result_day = max_day;
            flower_count++;
        }
        // 아니면 불가능 판정 후 윗 while문 조건 불충족으로 탈출한다
        else {
            tf = false;
        }

        index++;
    }

    // 출력
    tf ? cout << flower_count : cout << 0;

    return 0;
}