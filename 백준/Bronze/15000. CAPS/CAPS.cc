#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; str[i] != NULL; i++) {
		str[i] = toupper(str[i]);
	}

	cout << str;

	return 0;
}