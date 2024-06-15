#include <iostream>
using namespace std;
int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int e, f;
	if (a % c == 0) {
		e = a / c;
	}
	else {
		e = (a / c) + 1;
	}

	if (b % d == 0) {
		f = b / d;
	}
	else {
		f = (b / d) + 1;
	}

	e < f ? cout << l - f : cout << l - e;

	return 0;
}