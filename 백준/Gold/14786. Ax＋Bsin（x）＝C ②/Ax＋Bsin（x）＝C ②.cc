#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ld = long double;

// f(x) = Ax + B * sin(x) - C
ld f(ld x, ld A, ld B, ld C) {
	return A * x + B * sinl(x) - C;
}

// f'(x) = A + B * cos(x)
ld df(ld x, ld A, ld B) {
	return A + B * cosl(x);
}

ld Newton_Raphson(ld A, ld B, ld C, ld tolerance = 1e-20, int max_iteration = 1000000) {
	ld x0 = 0.0;
	ld x1;
	int iteration = 0;

	while (iteration < max_iteration) {
		ld fx = f(x0, A, B, C);
		ld dfx = df(x0, A, B);

		if (fabs(dfx) < 1e-20) {
			return x0;
		}

		x1 = x0 - fx / dfx;

		if (fabs(x1 - x0) < tolerance) {
			return x1;
		}

		x0 = x1;
		++iteration;
	}

	return x0;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	ld root = Newton_Raphson(A, B, C);
	cout << fixed << setprecision(15) << root << endl;

	return 0;
}