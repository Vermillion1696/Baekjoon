#include <iostream>
using namespace std;

int main() {
	int h, m, s, add;
	cin >> h >> m >> s >> add;

	h += add / 3600;
	add %= 3600;

	m += add / 60;
	add %= 60;

	s += add;

	int q;
	if (s >= 60) {
		q = s / 60;
		s -= 60;
		m += q;
	}
	if (m >= 60) {
		q = m / 60;
		m -= 60;
		h += q;
	}
	if (h >= 24) {
		h %= 24;
	}

	cout << h << " " << m << " " << s;

	return 0;
}