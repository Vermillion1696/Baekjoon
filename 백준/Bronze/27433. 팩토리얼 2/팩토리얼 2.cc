#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long int total = 1;
	for (int i = 1; i <= n; i++) {
		total *= i;
	}

	cout << total;
	return 0;
}