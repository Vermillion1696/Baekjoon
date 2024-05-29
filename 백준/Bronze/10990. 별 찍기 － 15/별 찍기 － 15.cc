#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "*";
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n - 1; j >= i; j--) {
			cout << " ";
		}

		if (i == 1) {
			cout << "*";
		}
		else {
			cout << "*";
			for (int j = 2 * i - 3; j > 0; j--) {
				cout << " ";
			}
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}