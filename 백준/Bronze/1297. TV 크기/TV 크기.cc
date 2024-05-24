#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double d, h, w, ratio;
	cin >> d >> h >> w;

	ratio = sqrt((d * d) / (h * h + w * w));

	cout << floor(sqrt((d * d) - (ratio * ratio * w * w) / ratio * ratio)) << " " << floor(sqrt(((d * d) - (ratio * ratio * h * h)) / ratio * ratio));
}