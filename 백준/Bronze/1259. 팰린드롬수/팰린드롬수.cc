#include <iostream>
using namespace std;

int main() {
	string str;
	
	while (true) {
		cin >> str;

		if (str == "0") return 0;

		bool palindrome = true;
		for (int i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - 1 - i]) {
				palindrome = false;
				break;
			}
		}

		cout << (palindrome ? "yes" : "no") << endl;
	}
}