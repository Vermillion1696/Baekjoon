#include <iostream>
#include <stack>
using namespace std;
// 주석 : 내 힘으로 코드를 12시간동안 고민 끝에 만들어봤는데 시간 초과가 떠서...
// 아무리 생각을 해도 코드를 싹 갈아 엎어야 할 것 같길래 다른 사람의 코드를 보고 방향성만 참고 하기로 했다
// 근데 이렇게 짧게도 풀리는 문제일줄은 상상도 못 했다 이런 방식으로 풀 수 있다는게 너무 놀라웠다
// 아직 어려운 문제는 건들지 말자...

// pair stack s 선언
int arr[500000];
long long int total = 0;
stack<pair<int, int>> s;

int main() {

    // 숫자 개수
    int n;
    cin >> n;

    // 배열에 원 데이터 저장
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {

        // 보이는 쌍 카운팅
        int current = 1;

        // 스택이 비어있지 않고, 제일 위에 있는게 arr[i]보다 작거나 같을 때
        while (!s.empty() && s.top().first <= arr[i]) {

            if (s.top().first == arr[i]) {

                // 현재 몇 개의 같은 수가 있는가 ? -> current
                current += s.top().second;

                // 같은 수 끼리 서로 보는 경우의 수 (internal)
                total += s.top().second;

                s.pop();
            }

            // 다르면 최종 답에 넣음
            // 함수 개수 정하는 방식 (external)
            // ex. 7 7 7 7 6 6 6 (7x4, 6x3), 몇 개의 경우의 수 ? -> 12
            // internal + external = 총 경우의 수 (사다리꼴)
            else {
                total += s.top().second;
                s.pop();
            }
        }

        // while을 나왔으므로 스택은 비었거나 제일 위가 arr[i]보다 작다
        if (!s.empty()) {
            total++;
        }

        // 스택에 저장되는 값은 모두 pivot (arr[i]) 보다 크거나 같은 값
        s.push({ arr[i], current });
    }
    
    cout << total;
}
