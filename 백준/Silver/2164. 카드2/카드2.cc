#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // 숫자 입력
    int n;
    cin >> n;
    n++;

    // 덱에 front로 6부터 1까지 넣음
    deque<int> deck;
    while (--n) {
        deck.push_front(n);
    }

    int temp;
    bool tf = 1;

    // 덱에 한 개만 남을 때까지
    while (deck.size() != 1) {

        // Case 1 : 버리기
        if (tf) {
            deck.pop_front();
            tf = 0;
        }

        // Case 2 : 빼서 back에 넣기
        if (!tf) {
            temp = deck.front();
            deck.pop_front();
            deck.push_back(temp);
            tf = 1;
        }
    }

    cout << deck.back();

    return 0;
}