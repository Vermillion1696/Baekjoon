#include <iostream>
#include <cctype>
using namespace std;

int main() {
	int size;
	cin >> size;

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = tolower(str[i]);
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = toupper(str[i]);
		}
	}

	cout << str;
}