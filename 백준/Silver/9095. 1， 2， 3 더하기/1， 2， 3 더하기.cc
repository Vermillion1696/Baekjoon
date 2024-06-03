#include <iostream>
using namespace std;

int main() {
	int arr[10];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	for (int i = 3; i < 10; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	int tc, index;
	cin >> tc;
	while (tc--) {
		cin >> index;
		cout << arr[index - 1] << "\n";
	}

	return 0;
}