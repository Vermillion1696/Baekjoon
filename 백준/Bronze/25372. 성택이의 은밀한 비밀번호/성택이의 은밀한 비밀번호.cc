#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int times;
	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> str;

		if (str.length() >= 6 && str.length() <= 9) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	
	return 0;
}