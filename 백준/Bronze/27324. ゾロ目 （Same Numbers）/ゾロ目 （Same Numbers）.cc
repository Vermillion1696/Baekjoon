#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	if (str[0] == str[1]) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}