#include <iostream>
using namespace std;

int main() {
	string str;
	int age, weight;

	while (1) {
		cin >> str;
		cin >> age >> weight;

		if (str == "#" || age == 0 || weight == 0) {
			break;
		}
		else {
			cout << str;

			if (age > 17 || weight >= 80) {
				cout << " Senior\n";
			}
			else {
				cout << " Junior\n";
			}
		}
	}

	return 0;
}