#include <iostream>
#include <string>
using namespace std;

int main() {
	double a, b, c;
	cout << fixed;
	cout.precision(2);

	int times;
	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> a >> b >> c;
		cout << "$" << double(a * (b * c)) << "\n";
	}

	return 0;
}