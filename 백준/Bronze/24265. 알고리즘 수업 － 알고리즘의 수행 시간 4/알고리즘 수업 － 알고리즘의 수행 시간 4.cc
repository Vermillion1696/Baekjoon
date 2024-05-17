#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;

	long long int cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += n - i;
	}

	cout << cnt << endl << 2;
	return 0;
}