#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[9];

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	
	bool tf = 1;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != 0 && arr[i] != 1) {
			tf = 0;
			break;
		}
	}

	if (!tf) {
		cout << "F";
	}
	else {
		cout << "S";
	}

	return 0;
}