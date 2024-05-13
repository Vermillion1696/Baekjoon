#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	int total = a * 8 + b * 3;
	if (total > 28) {
		cout << total - 28;
	}
	else {
		cout << 0;
	}

	return 0;
}