#include <iostream>
using namespace std;

int main() {
	int burger[3], drink[2];

	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
	}

	int minburger = burger[0];
	for (int i = 1; i < 3; i++) {
		if (minburger > burger[i]) {
			minburger = burger[i];
		}
	}

	int mindrink;
	drink[0] > drink[1] ? mindrink = drink[1] : mindrink = drink[0];
	
	cout << minburger + mindrink - 50;

	return 0;

}