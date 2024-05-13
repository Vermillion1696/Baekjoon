#include <iostream>
using namespace std;

int main() {
	int times;
	cin >> times;

	int total = 0;
	for (int i = 0; i < times; i++) {
		int temp;
		cin >> temp;
		total += temp;
	}

	if (total > 0) {
		cout << "Right";
	}
	else if (total < 0) {
		cout << "Left";
	}
	else {
		cout << "Stay";
	}

	return 0;
}