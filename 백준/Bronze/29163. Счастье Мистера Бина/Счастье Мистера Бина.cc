#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int num[2] = { 0, };
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp % 2 == 0) {
			num[0]++;
		}
		else {
			num[1]++;
		}
	}

	if (num[0] > num[1]) {
		cout << "Happy";
	}
	else {
		cout << "Sad";
	}

	return 0;
}