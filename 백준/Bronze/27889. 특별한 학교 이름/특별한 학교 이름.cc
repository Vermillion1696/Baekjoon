#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	if (str.compare("NLCS") == 0) {
		cout << "North London Collegiate School";
	}
	else if (str.compare("BHA") == 0) {
		cout << "Branksome Hall Asia";
	}
	else if (str.compare("KIS") == 0) {
		cout << "Korea International School";
	}
	else if (str.compare("SJA") == 0) {
		cout << "St. Johnsbury Academy";
	}

	return 0;
}