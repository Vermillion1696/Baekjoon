#include <iostream>
using namespace std;

int main() {
	int a[5];
	int total = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	total = 6 * a[0] + 3 * a[1] + 2 * a[2] + 1 * a[3] + 2 * a[4];
	cout << total << endl;

	total = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	total = 6 * a[0] + 3 * a[1] + 2 * a[2] + 1 * a[3] + 2 * a[4];
	cout << total;

	return 0;
}