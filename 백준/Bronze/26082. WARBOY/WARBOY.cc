#include <iostream>
#include <string>
using namespace std;

int main() {
	int enemyPrice, enemyFac, warboyPrice, warboyFac;
	cin >> enemyPrice >> enemyFac >> warboyPrice;

	warboyFac = 3 * enemyFac / enemyPrice;
	cout << warboyFac * warboyPrice;
	
	return 0;
}