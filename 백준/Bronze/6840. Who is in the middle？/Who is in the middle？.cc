#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c) {
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c) {
		temp = b;
		b = c;
		c = temp;
	}

	cout << b;

	return 0;
}
