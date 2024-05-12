#include <iostream>
using namespace std;

int main() {
	char str[4];
	cin >> str;

	char temp;
	temp = str[0];
	str[0] = str[2];
	str[2] = temp;

	cout << str;

	return 0;
}