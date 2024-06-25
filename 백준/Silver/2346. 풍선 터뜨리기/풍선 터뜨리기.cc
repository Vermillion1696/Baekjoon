#include <iostream>
#include <deque>
using namespace std;
#define index first
#define movement second

// move > 0 이면 실제 move는 move - 1회
void positive(deque<pair<int, int>>& dq, int move) {
	while (--move) {
		dq.push_back(make_pair(dq.front().index, dq.front().movement));
		dq.pop_front();
	}
}

// move < 0 이면 실제 move는 abs(move)회
void negative(deque<pair<int, int>>& dq, int move) {
	move *= -1;
	while (move--) {
		dq.push_front(make_pair(dq.back().index, dq.back().movement));
		dq.pop_back();
	}
}

int main() {
	deque<pair<int, int>> dq;
	int n, value;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> value;
		dq.push_back(make_pair(i, value));
	}

	int move;
	while (1) {
		cout << dq.front().index << " ";
		move = dq.front().movement;
		dq.pop_front();

		// 디버깅용 코드
		/*
		cout << "\n Queue : ";
		deque<pair<int, int>>::iterator iter = dq.begin();
		for (iter = dq.begin(); iter != dq.end(); ++iter) {
			cout << iter->movement << " ";
		}
		cout << endl;
		*/

		if (dq.empty()) {
			break;
		}
		
		if (move > 0) {
			positive(dq, move);
		}
		else {
			negative(dq, move);
		}
	}

	return 0;
}