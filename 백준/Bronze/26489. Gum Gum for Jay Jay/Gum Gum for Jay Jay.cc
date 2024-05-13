#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int times = 0;

	while (getline(cin, str)) {
		times++;
	}

	cout << times;

	return 0;
}