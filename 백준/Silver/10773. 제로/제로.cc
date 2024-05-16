#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	// k개의 정수를 입력 받고, 이를 stack s에 넣음
	int k;
	cin >> k;
	stack <int> s;

	int temp;
	while (k--) {
		cin >> temp;
		
		// 입력 받은 수가 0이면 제일 최근 수 지우기
		if (temp == 0) {
			s.pop();
		}
		// 아니면 입력 받은 수 스택에 넣기
		else {
			s.push(temp);
		}
	}

	// 합 구하기
	int total = 0;
	while (s.size() != 0) {
		total += s.top();
		s.pop();
	}

	cout << total;

	return 0;
}