#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		double slice_area, whole_area;
		int slice_price, whole_price;
		double whole_radius;
		
		cin >> slice_area >> slice_price;
		cin >> whole_radius >> whole_price;
		whole_area = whole_radius * whole_radius * 3;

		if (whole_area / whole_price > slice_area / slice_price) {
			cout << "Whole pizza" << endl;
		}
		else {
			cout << "Slice of pizza" << endl;
		}
	}

	return 0;
}