#include <iostream>
using namespace std;
#define ll long long

/*
// 최대공약수
ll GCD(ll a, ll b) {
	ll total = 1, minimum = min(a, b);
	for (ll i = 2; i <= minimum; i++) {
		while (a % i == 0 && b % i == 0) {
			total *= i;
			a /= i;
			b /= i;
		}
	}
	return total;
}

// 최소공배수
ll LCM(ll a, ll b, ll gcd) {
	return (a * b) / gcd;
}
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll totalUP = a * d + b * c, totalDOWN = b * d;

	// 기약분수 만들기
	ll minimum = min(totalUP, totalDOWN);
	for (ll i = 2; i * i <= minimum; i++) {
		while (totalUP % i == 0 && totalDOWN % i == 0) {
			totalUP /= i;
			totalDOWN /= i;
		}
	}

	cout << totalUP << " " << totalDOWN;

	return 0;
}