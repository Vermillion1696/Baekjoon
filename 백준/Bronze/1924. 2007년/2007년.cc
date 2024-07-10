#include <iostream>
using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x - 1; i++) {
		y += month[i];
	}

	switch (y % 7) {
	case 1:
		cout << "MON";
		return 0;
	case 2:
		cout << "TUE";
		return 0;
	case 3:
		cout << "WED";
		return 0;
	case 4:
		cout << "THU";
		return 0;
	case 5:
		cout << "FRI";
		return 0;
	case 6:
		cout << "SAT";
		return 0;
	case 0:
		cout << "SUN";
		return 0;
	}
}