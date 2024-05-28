#include <iostream>
using namespace std;

void printStar(int n, int cnt) {

	if (cnt == 0) {
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";

		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";

		cnt--;
		printStar(n, cnt);
	}
}

int main() {
	int n;
	cin >> n;

	printStar(n, n);

	return 0;
}