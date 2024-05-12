#include <iostream>
using namespace std;

int main() {
	int total = 0;

	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		total += temp;
	}

	cout << total;
	
	return 0;
}
