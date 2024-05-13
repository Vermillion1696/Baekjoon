#include <iostream>
using namespace std;

int main() {
	int times;
	cin >> times;

	int timesv, timesi;
	timesv = times / 5;
	timesi = times % 5;

	for (int i = 0; i < timesv; i++) {
		cout << "V";
	}
	for (int i = 0; i < timesi; i++) {
		cout << "I";
	}

	return 0;
}