#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<int> able;
bool day[8];
int arr[100001];

int main() {
	int n;
	cin >> n;

	int val;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		val %= 7;
		arr[i] = val;
	}
	
	day[arr[1]] = true;
	able.insert(0);
	able.insert(arr[1]);
	vector<int> lazy;

	for (int i = 2; i <= n; i++) {
		for (auto iter = able.begin(); iter != able.end(); iter++) {
			int cur = *iter + arr[i];
			if (cur > 7) cur %= 7;

			// 이전에 방문하지 않은 day이면
			if (!day[cur]) {
				day[cur] = true;
				lazy.push_back(cur);
			}
		}

		for (auto iter : lazy) {
			able.insert(iter);
		}
		lazy.clear();

		if (day[4]) break;
	}

	day[4] ? cout << "YES" : cout << "NO";

	return 0;
}