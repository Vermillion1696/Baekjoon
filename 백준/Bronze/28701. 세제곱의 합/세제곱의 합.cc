#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;

	long long int total = 0;
	for (int i = 1; i <= n; i++) {
		total += i;
	}
	cout << total << endl;
	cout << total * total << endl;

	total = 0;
	for (int i = 1; i <= n; i++) {
		total += i * i * i;
	}
	cout << total;

	return 0;
}