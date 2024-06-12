#include <iostream>
#include <string>
using namespace std;

int main() {
	string str[3];
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}

	int num;
	for (int i = 0; i < 3; i++) {
		if (str[i][0] >= '1' && str[i][0] <= '9') {
			num = stoi(str[i]) + 3 - i;
		}
	}

	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0 && num % 5 != 0) {
		cout << "Fizz";
	}
	else if (num % 3 != 0 && num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}
}