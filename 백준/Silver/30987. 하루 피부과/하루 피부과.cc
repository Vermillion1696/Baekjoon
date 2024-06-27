#include <iostream>
using namespace std;

void integrate(const int& x1, const int& x2, const long long int& a, const long long int& b, const long long int& c) {
	long long int total = 0;

	total += a * x1 * x1 * x1;
	total += b * x1 * x1;
	total += c * x1;
	total *= -1;

	total += a * x2 * x2 * x2;
	total += b * x2 * x2;
	total += c * x2;

	cout << total;
}

int main() {
	long long int x1, x2, a, b, c, d, e;
	cin >> x1 >> x2 >> a >> b >> c >> d >> e;

	integrate(x1, x2, a / 3, (b - d) / 2, c - e);

	return 0;
}