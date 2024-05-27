#include <iostream>
using namespace std;

void printStar(int x, int y, int n) {
	if (n == 1) {
		cout << "*";
		return;
	}
	else if ((x / (n / 3)) % 3 == 1 && (y / (n / 3)) % 3 == 1) {
		cout << " ";
	}
	else {
		printStar(x, y, n / 3);
	}
}

int main() {
	int n;
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printStar(x, y, n);
		}
		cout << "\n";
	}
}