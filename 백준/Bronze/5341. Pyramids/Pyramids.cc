#include <iostream>
using namespace std;

int main() {
	int n;
	int total = 0;
	cin >> n;

	while (n > 0) {
		for (int i = 1; i <= n; i++) {
			total += i;
		}

		cout << total << "\n";
		total = 0;

		cin >> n;
	}

	return 0;
}