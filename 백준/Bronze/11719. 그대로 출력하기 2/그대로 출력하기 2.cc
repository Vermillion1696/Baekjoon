#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char c;
	
	while (c = getchar()) {

		if (c == EOF) break;
		cout << c;
	}

	return 0;
}