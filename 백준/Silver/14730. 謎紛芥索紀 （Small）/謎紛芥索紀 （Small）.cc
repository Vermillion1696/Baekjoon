#include <iostream>
using namespace std;

int main() {
	int group;
	cin >> group;

	long long int total = 0, a, n;
	while (group--) {
		cin >> a >> n;
		total += a * n;
	}

	cout << total;

	return 0;
}