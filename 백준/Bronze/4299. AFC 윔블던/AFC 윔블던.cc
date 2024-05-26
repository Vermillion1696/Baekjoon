#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int add, subtract, x, y;
	cin >> add >> subtract;

	if (add < subtract) {
		cout << "-1";
		return 0;
	}

	x = (add + subtract) / 2;
	y = (add - subtract) / 2;

	if (x < y) {
		swap(x, y);
	}
	
	if (x + y != add) {
		cout << "-1";
		return 0;
	}
	if (x - y != subtract) {
		cout << "-1";
		return 0;
	}

	cout << x << " " << y;
	
	return 0;
}