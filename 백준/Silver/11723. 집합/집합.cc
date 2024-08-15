#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
void write_string(const string& str) {
	ofstream writeFile;
	writeFile.open("baekjoon.txt", ios::app);

	writeFile.write(str.c_str(), str.size());
	writeFile.write("\n", 1);
	writeFile.close();

	return;
}
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int operation;
	cin >> operation;

	int S = 0, x;
	string str;
	while (operation--) {
		cin >> str;

		if (str == "add") {
			cin >> x;
			S |= (1 << x);
		}
		else if (str == "remove") {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			bool isElement = S & (1 << x);
			cout << isElement << "\n";
			//write_string(to_string(isElement));
		}
		else if (str == "toggle") {
			cin >> x;
			if (S & (1 << x)) S &= ~(1 << x);
			else (S |= (1 << x));
		}
		else if (str == "all") {
			S = (1 << 21) - 1;
		}
		else {
			S = 0;
		}
	}

	return 0;
}