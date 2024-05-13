#include <iostream>
using namespace std;

int main() {
	string str = "WelcomeToSMUPC";
	int n;
	cin >> n;
	n--;
	cout << str[n % 14];
	return 0;
}