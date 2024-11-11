#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
constexpr double pi = 3.14159265358979323846;

int main() {
	double area;
	cin >> area;

	double radius = sqrt(area / pi);
	double circum = 2 * pi * radius;

	cout.precision(7);
	cout << fixed << circum;

	return 0;
}