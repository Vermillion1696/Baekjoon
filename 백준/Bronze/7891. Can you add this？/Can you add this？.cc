#include <iostream>
using namespace std;

int main() {
	int times;
	cin >> times;

	int a, b;
	for (int i = 0; i < times; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	
	return 0;
}