#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

// 소수인지 판별
// 0, 1 -> false
// 2 -> true
// 2로 나누어 떨어짐 -> false
// 3부터 i += 2 하면서 i^2 <= n인 동안 나누어 떨어지면 -> false
bool isPrime(const ll n) {
	if (n < 2) return false;
	else if (n == 2) return true;
	else if (n % 2 == 0) return false;

	for (ll i = 3; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {
	int tc;
	ll n;
	cin >> tc;

	while (tc--) {
		cin >> n;
		while (!isPrime(n)) n++;
		cout << n << "\n";
	}

	return 0;
}