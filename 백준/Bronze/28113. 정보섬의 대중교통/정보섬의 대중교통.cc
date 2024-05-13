#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if (a < b) {
		cout << "Bus";
	}
	else if (a > b) {
		cout << "Subway";
	}
	else {
		cout << "Anything";
	}

	return 0;
}