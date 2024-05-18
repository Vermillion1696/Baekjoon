#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// 왼쪽 큐 회전
void leftMove(deque<int>& dq, long long int* total, int target) {
	while (dq.front() != target) {
		dq.push_back(dq.front());
		dq.pop_front();
		(*total)++;
	}
}

// 오른쪽 큐 회전
void rightMove(deque<int>& dq, long long int* total, int target) {
	while (dq.front() != target) {
		dq.push_front(dq.back());
		dq.pop_back();
		(*total)++;
	}
}

int main() {

	// deque, iterator, n, m
	deque<int> dq;
	deque<int> ::iterator iter;
	int n, m;
	cin >> n >> m;

	// 입력
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int temp;
	int index;
	long long int total = 0;
	while (m--) {

		// 찾는 숫자
		cin >> temp;

		// deque의 elements는 중복이 아니다가 보장된다
		// index로 target의 출현 위치 저장
		auto iter = find(dq.begin(), dq.end(), temp);
		index = distance(dq.begin(), iter);

		// 왼쪽 회전, 오른쪽 회전 결정 조건문
		if (index <= dq.size() - index) {
			leftMove(dq, &total, temp);
		}
		else {
			rightMove(dq, &total, temp);
		}

		// dq.front() == target 이므로 pop
		dq.pop_front();
	}

	cout << total;

	return 0;
}