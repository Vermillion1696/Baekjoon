#include <iostream>
using namespace std;

int main() {
	int arr[1000];

	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < 1000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	int n;
	cin >> n;
	cout << arr[n - 1] % 10007;

	return 0;
}