#include <iostream>
using namespace std;

int main() {
	int n, price;
	cin >> n >> price;

	if (100 * n >= price) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}