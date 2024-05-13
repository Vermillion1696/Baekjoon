#include <iostream>
using namespace std;

int main() {
	char a;
	cin >> a;

	if (a == 'M') {
		cout << "MatKor";
	}
	else if (a == 'W') {
		cout << "WiCys";
	}
	else if (a == 'C') {
		cout << "CyKor";
	}
	else if (a == 'A') {
		cout << "AlKor";
	}
	else {
		cout << "$clear";
	}

	return 0;
}