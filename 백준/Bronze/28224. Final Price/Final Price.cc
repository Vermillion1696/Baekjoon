#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long total = 0;
	long long val;

	while (n--) {
		cin >> val;
		total += val;
	}

	cout << total;
}