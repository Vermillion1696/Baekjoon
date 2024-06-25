#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int initialState[2][100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int size;
	cin >> size;
	
	// initialState[0][n] : queue인지 stack인지
	// initialState[1][n] : 자료구조에 들어있는 원소
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < size; j++) {
			cin >> initialState[i][j];
		}
	}

	// queue인 경우만 실제 queue에 값을 넣음
	queue<int> q;
	for (int i = size - 1; i >= 0; i--) {
		if (initialState[0][i] == 0) {
			q.push(initialState[1][i]);
		}
	}

	int pushSize;
	cin >> pushSize;

	int element;
	while (pushSize--) {
		cin >> element;
		q.push(element);

		cout << q.front() << " ";
		q.pop();
	}
}