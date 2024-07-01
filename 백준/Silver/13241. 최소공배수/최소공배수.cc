#include <iostream>
using namespace std;
#define ll long long int

ll GCD(ll a, ll b) {
	ll total = 1, minimum = min(a, b);
	
	// 2부터 둘 중 작은 수까지 나눠봄
	for (int i = 2; i <= minimum; i++) {
		while (a % i == 0 && b % i == 0) {
			total *= i;
			a /= i;
			b /= i;
		}
	}

	return total;
}

ll LCM(const ll& a, const ll& b, const ll& gcd) {
	return (a * b) / gcd;
}

int main() {

	ll lcm, gcd, a, b;
	cin >> a >> b;

	gcd = GCD(a, b);
	lcm = LCM(a, b, gcd);

	cout << lcm;
}