#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 1; i <= n; i++) {
		getline(cin, str);
		cout << i << ". " << str << "\n";
	}

	return 0;
}