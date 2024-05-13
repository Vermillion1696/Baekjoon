#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	if (a > b) {
		cout << 1;
	}
	else if (a == b) {
		cout << 0;
	}
	else {
		cout << -1;
	}

	return 0;
}