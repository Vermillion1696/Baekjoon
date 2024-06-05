#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int stringtoint(string str) {
	int total = 0;
	for (int i = 0; i < str.length(); i++) {
		total += pow(10, str.length() - i - 1) * (str[i] - '0');
	}
	return total;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	cout << stringtoint(a) + stringtoint(b) - stringtoint(c) << endl;
	
	a += b;
	cout << stringtoint(a) - stringtoint(c);

	return 0;
}