#include <iostream>
using namespace std;

long double pow(long double a, int b) {
	long double total = 1;
	if (b == 0) {
		return total;
	}
	else {
		for (int i = 0; i < b; i++) {
			total *= a;
		}
		return total;
	}
}

int main() {
	cout << fixed;
	cout.precision(2);

	double n;
	long double total;

	do {
		total = 1;
		cin >> n;

		if (n == 0) {
			return 0;
		}

		for (int i = 1; i <= 4; i++) {
			total += pow(n, i);
		}

		cout << total << "\n";
	} while (1);

	return 0;
}