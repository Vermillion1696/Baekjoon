#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int t, m;
	int total = 0;
	cin >> t >> m;

	total += (t - 9) * 60;
	total += m;
	cout << total;

	return 0;
}