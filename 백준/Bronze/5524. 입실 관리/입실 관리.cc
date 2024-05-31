#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	string str;

	cin >> tc;

	while (tc--) {
		cin >> str;

		for (int i = 0; str[i] != NULL; i++) {
			cout << char(tolower(str[i]));
		}

		cout << "\n";
	}

	return 0;
}