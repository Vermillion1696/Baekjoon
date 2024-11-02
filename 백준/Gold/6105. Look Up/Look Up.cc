#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int N[100001];

int main() {
	
	// 키, 현재 인덱스
	stack<pair<int, int>> s;
	int cows;
	cin >> cows;

	int height;
	for (int i = 1; i <= cows; i++) {
		cin >> height;

		if (s.empty() || s.top().first >= height) {
			s.push({ height, i });
		}
		else {
			while (!s.empty() && s.top().first < height) {
				int cur_idx = s.top().second;
				N[cur_idx] = i;
				s.pop();
			}
			s.push({ height, i });
		}
	}

	for (int i = 1; i <= cows; i++) {
		cout << N[i] << '\n';
	}

	return 0;
}