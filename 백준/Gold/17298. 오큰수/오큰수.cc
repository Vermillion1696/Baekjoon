#include <iostream>
#include <stack>
using namespace std;
int arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// arr[index]에 값이 없으면 레이저 신호를 수신하는 타워가 없으므로
	// 저장되는 값이 없을 때 -1이다
	for (int i = 0; i < 1000000; i++) {
		arr[i] = -1;
	}

	// pair stack, testcase
	stack<pair<int, int>> s;
	int tc;
	cin >> tc;

	// tc 크기의 동적 배열 선언
	int temptc = tc;

	int index = 0;
	int temp;
	while (tc--) {
		cin >> temp;

		// 스택이 비거나 왼쪽 수가 더 크거나 같으면 정지
		while (!s.empty() && s.top().first < temp) {
			arr[s.top().second] = temp;
			s.pop();
		}

		s.push(make_pair(temp, index));
		index++;
	}

	// 출력
	for (int i = 0; i < temptc; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}