#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long double total = 0.0;
	long double val1, val2;
	
	while (n--) {
		cin >> val1 >> val2;
		total += val1 * val2;
	}

	cout << total;
}