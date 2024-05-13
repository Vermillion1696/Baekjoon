#include <iostream>
using namespace std;

int main() {
	int arr[6];
	int total = 0;

	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 6; i++) {
		total += 5 * arr[i];
	}

	cout << total;

	return 0;
}