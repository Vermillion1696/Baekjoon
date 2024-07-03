#include <iostream>
using namespace std;

int main() {
	long long int a, b, c;
	cin >> a >> b >> c;

	if (a * b < c) {
		cout << 0;
		return 0;
	}

	cout << a * b - c;
	return 0;
}