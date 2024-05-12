#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n1, n2, n12;
	cin >> n1 >> n2 >> n12;

	cout << floor((n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
	return 0;
}