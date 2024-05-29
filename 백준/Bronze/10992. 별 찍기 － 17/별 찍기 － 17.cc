#include <iostream>
using namespace std;

int main() {
	int n, times;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			cout << " ";
		}

		if (i == 1) {
			cout << "*";
		}
		else if (i == n) {
			times = 2 * n - 1;
			while (times--) {
				cout << "*";
			}
		}
		else {
			cout << "*";
			times = 2 * i - 3;
			while (times--) {
				cout << " ";
			}
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}