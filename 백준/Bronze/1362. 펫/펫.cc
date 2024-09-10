#include <iostream>
using namespace std;

int main() {
	int o, w, cnt = 0;
	while (1) {
		cnt++;
		bool is_alive = true;
		cin >> o >> w;
		if (o == 0 && w == 0) break;

		char c;
		int n;
		while (1) {
			cin >> c >> n;
			if (c == '#' && n == 0) break;

			if (is_alive) {
				switch (c) {
				case 'E':
					w -= n;
					break;
				case 'F':
					w += n;
					break;
				}
			}

			if (w <= 0) is_alive = false;
		}

		cout << cnt << ' ';
		if (w <= 0) cout << "RIP\n";
		else if (o / 2 < w && w < o * 2) cout << ":-)\n";
		else cout << ":-(\n";
	}

	return 0;
}