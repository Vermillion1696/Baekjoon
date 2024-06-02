#include <iostream>
#include <stack>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	int arr[3];

	cout << "Gnomes:\n";
	while (tc--) {
		bool ordered = 1;

		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}

		if (arr[0] < arr[1] && arr[2] < arr[1]) {
			ordered = 0;
		}
		else if (arr[0] > arr[1] && arr[2] > arr[1]) {
			ordered = 0;
		}

		if (ordered) {
			cout << "Ordered\n";
		}
		else {
			cout << "Unordered\n";
		}
	}

	return 0;
}