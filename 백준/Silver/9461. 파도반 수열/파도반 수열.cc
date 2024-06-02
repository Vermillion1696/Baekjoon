#include <iostream>
using namespace std;
long long int arr[100];

int main() {
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;
	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 3] + arr[i - 2];
	}

	int tc, num;
	cin >> tc;

	while (tc--) {
		cin >> num;
		cout << arr[num - 1] << "\n";
	}

	return 0;
}