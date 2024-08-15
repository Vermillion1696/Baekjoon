#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도를 빠르게 하기 위한 설정
    cin.tie(0);

    int N; // 과일의 개수
    cin >> N;
    vector<int> fruits(N); // 과일의 종류를 저장하는 벡터

    // 과일의 종류를 입력 받음
    for (int i = 0; i < N; ++i) {
        cin >> fruits[i];
    }

    int count[200001] = {};
    int left = 0, right = 0;
    int max_len = 0;
    int kind = 0;

    // right 포인터를 오른쪽으로 이동시키며 탐색
    while (right < N) {

        // 현재 과일을 추가할 때, 해당 과일이 처음 등장하는 경우 종류 수 증가
        if (count[fruits[right]] == 0) {
            kind++;
        }
        count[fruits[right]]++;

        // 만약 과일의 종류가 두 종류를 초과하는 경우
        while (kind > 2) {

            // left 포인터를 오른쪽으로 이동시켜 구간을 줄여 나감
            count[fruits[left]]--;

            // 만약 left 포인터가 가리키는 과일이 구간에서 더 이상 존재하지 않게 되면 종류 수 감소
            if (count[fruits[left]] == 0) {
                kind--;
            }
            left++;
        }

        max_len = max(max_len, right - left + 1);
        right++;
    }

    cout << max_len;
    return 0;
}