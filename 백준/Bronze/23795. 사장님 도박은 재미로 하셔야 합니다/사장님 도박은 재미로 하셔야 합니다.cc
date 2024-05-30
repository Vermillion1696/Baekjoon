#include <iostream>
using namespace std;

int main() {
	int n = 0;
	long long int total = 0;

	while (n != -1) {
		cin >> n;
		if (n != -1) {
			total += n;
		}
	}

	cout << total;

	return 0;
}