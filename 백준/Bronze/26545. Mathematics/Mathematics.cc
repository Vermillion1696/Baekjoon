#include <iostream>
#include <string>
using namespace std;

int main() {
	int temp;
	int times;
	cin >> times;

	int total = 0;
	for (int i = 0; i < times; i++) {
		cin >> temp;
		total += temp;
	}

	cout << total;

	return 0;
}