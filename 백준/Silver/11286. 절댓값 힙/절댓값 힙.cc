#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#define faster_output cin.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	faster_output

	priority_queue<int> pq_neg;
	priority_queue<int, vector<int>, greater<int>> pq_pos;

	int command_cnt, value;
	cin >> command_cnt;

	while (command_cnt--) {
		cin >> value;

		if (value > 0) pq_pos.push(value);
		else if (value < 0) pq_neg.push(value);
		else {
			if (pq_pos.empty() && pq_neg.empty()) cout << 0 << "\n";
			else if (pq_pos.empty()) {
				cout << pq_neg.top() << "\n";
				pq_neg.pop();
			}
			else if (pq_neg.empty()) {
				cout << pq_pos.top() << "\n";
				pq_pos.pop();
			}
			else if (abs(pq_pos.top()) < abs(pq_neg.top())) {
				cout << pq_pos.top() << "\n";
				pq_pos.pop();
			}
			else {
				cout << pq_neg.top() << "\n";
				pq_neg.pop();
			}
		}
	}

	return 0;

	return 0;
}