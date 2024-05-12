#include <iostream>
using namespace std;

int main() {
	int ax, ay, az, bx, by, bz, cx, cy, cz;
	cin >> ax >> ay >> az >> cx >> cy >> cz;

	bx = cx - az;
	by = cy / ay;
	bz = cz - ax;

	cout << bx << " " << by << " " << bz;
	return 0;
}