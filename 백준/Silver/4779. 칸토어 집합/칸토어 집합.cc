#include <iostream>
using namespace std;

void cantor(long long int x) {
	if (x == 1) {
		cout << "-";
	}
	else {
		cantor(x / 3);
		for (long long int i = 0; i < x / 3; i++) {
			cout << " ";
		}
		cantor(x / 3);
	}
}

int main() {
	int n;
	while (cin >> n) {
		long long int x = 1;
		for (int i = 1; i <= n; i++) {
			x *= 3;
		}
		cantor(x);
		cout << "\n";
	}
}