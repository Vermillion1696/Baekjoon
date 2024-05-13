#include <iostream>
#include <string>
using namespace std;

int main() {
	int times;
	cin >> times;
	string str;

	for (int i = 0; i < times; i++) {
		cin >> str;
		cout << str << " " << str << "\n";
	}

	return 0;
}