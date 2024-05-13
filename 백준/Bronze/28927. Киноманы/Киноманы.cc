#include <iostream>
using namespace std;

int main() {
	int t1, e1, f1, t2, e2, f2;
	cin >> t1 >> e1 >> f1 >> t2 >> e2 >> f2;

	int maxtotal = t1 * 3 + e1 * 20 + f1 * 120;
	int meltotal = t2 * 3 + e2 * 20 + f2 * 120;

	if (maxtotal > meltotal) {
		cout << "Max";
	}
	else if (maxtotal < meltotal) {
		cout << "Mel";
	}
	else {
		cout << "Draw";
	}

	return 0;
}