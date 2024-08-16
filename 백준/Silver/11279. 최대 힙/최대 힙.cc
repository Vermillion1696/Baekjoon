#include <iostream>
#include <queue>
#include <vector>
#define faster_output cin.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	faster_output

	priority_queue<int> pq;
	int command_cnt, value;
	cin >> command_cnt;

	while (command_cnt--) {
		cin >> value;

		if (value > 0) pq.push(value);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}