#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 테스트 케이스, current 타워의 높이, pair stack s
	int tn, height;
	stack<pair<int, int>> s;
	cin >> tn;

	int index = 1;
	while (tn--) {
		// 비교대상 높이 입력
		cin >> height;
		
		// 스택에 원소가 비거나 스택 제일 상단 원소가 height 보다 클 때 stop pop
		while (!s.empty() && s.top().first < height) {
			s.pop();
		}

		// 비었으면 (모든 stack에 담긴 것보다 큼 즉, 0)
		if (s.empty()) {
			cout << "0 ";
		}
		// 남아있으면 s.top()이 신호를 수신함
		else {
			cout << s.top().second << " ";
		}

		// stack에 넣기
		s.push(make_pair(height, index));
		index++;
	}

	return 0;
}