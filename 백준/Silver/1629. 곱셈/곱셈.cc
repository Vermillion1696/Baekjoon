#include <iostream>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;

// num % mod == 3이라면, num^pow % mod == (3 ^ pow) % mod
// -> a^n mod k을 알면 a^(2n) mod k, a^(2n-1) mod k도 알 수 있음
ll POW(ll num, ll pow, ll mod) {

	// Base Condition
	if (pow == 0) return 1 % mod;
	if (pow == 1) return num % mod;

	// pow / 2의 mod 결과값을 저장 후 재조합
	ll half_value = POW(num, pow / 2, mod);
	half_value = (half_value * half_value) % mod;

	// pow가 짝수인 경우 (pow == 2n)
	if (pow % 2 == 0) return half_value;
	// pow가 홀수인 경우 (pow == 2n + 1)
	else {
		half_value = (half_value * num) % mod;
		return half_value;
	}
}

int main() {
	fast_output;

	ll num, pow, mod;
	cin >> num >> pow >> mod;

	cout << POW(num, pow, mod);

	return 0;
}