#include <iostream>
using namespace std;

int main() {
	int sum[2];
	int a, b, c, d;

	for (int i = 0; i < 2; i++) {
		cin >> a >> b >> c >> d;
		sum[i] = a + b + c + d;
	}

	sum[0] < sum[1] ? cout << sum[1] : cout << sum[0];
	return 0;
}