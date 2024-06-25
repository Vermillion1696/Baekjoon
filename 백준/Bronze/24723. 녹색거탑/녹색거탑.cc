#include <iostream>
using namespace std;

int main() {
	int n, total = 1;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		total *= 2;
	}

	cout << total;

	return 0;
}