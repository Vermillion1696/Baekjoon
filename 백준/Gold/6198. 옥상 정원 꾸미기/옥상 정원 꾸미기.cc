#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 테스트 케이스, current 타워의 높이, pair stack s
	int tn, height;
	stack<int> s;
	cin >> tn;

	long long int total = 0;
	while (tn--) {
		// 비교대상 높이 입력
		cin >> height;
		
		// 스택에 원소가 비거나 스택 제일 상단 원소가 height 보다 클 때 stop pop
		while (!s.empty() && s.top() <= height) {
			s.pop();
		}

		// stack에 넣기
		s.push(height);

		// 쌍 더하기
		total += s.size() - 1;
	}

	cout << total;

	return 0;
}