#include <iostream>
#include <vector>
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;

int ret(char c) {
	if ('a' <= c && c <= 'z') return c - 'a' + 1;
	else if ('A' <= c && c <= 'Z') return c - 'A' + 27;
}

// 완화된 소수 판정
bool is_prime(ll num) {
	if (num == 1 || num == 2) return true;
	if (num % 2 == 0) return false;

	for (ll div = 3; div * div <= num; div += 2) {
		if (num % div == 0) return false;
	}

	return true;
}

int main() {
	fast_io;

	string str;
	cin >> str;

	ll sum = 0;
	for (auto iter : str) sum += ret(iter);

	cout << (is_prime(sum) ? "It is a prime word." : "It is not a prime word.");

	return 0;
}