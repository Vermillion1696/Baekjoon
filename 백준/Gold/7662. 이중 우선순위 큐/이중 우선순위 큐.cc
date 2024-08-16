#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc, command_cnt, value;
	char c;
	cin >> tc;

	while (tc--) {
		multiset<int> set;
		cin >> command_cnt;

		while (command_cnt--) {
			cin >> c >> value;

			if (c == 'I') {
				set.insert(value);
			}
			else {
				if (set.empty()) continue;

				if (value > 0) set.erase(--set.end());
				else set.erase(set.begin());
			}
		}

		set.empty() ? cout << "EMPTY\n" : cout << *(--set.end()) << " " << *(set.begin()) << "\n";
	}

	return 0;
}