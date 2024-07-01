#include <iostream>
using namespace std;
#define MAX 100001
#define ll long long int
ll tree[MAX];

// 최대공약수
ll GCD(ll a, ll b) {
	while (b != 0) {
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll treeCNT, gcd;
	cin >> treeCNT;

	// 입력을 받으면서, 모든 거리 집합에 대해 최대공약수를 구함
	for (ll i = 1; i <= treeCNT; i++) {
		cin >> tree[i];
		
		if (i == 2) {
			gcd = tree[i] - tree[i - 1];
		}
		else if (i > 2) {
			gcd = GCD(max(tree[i] - tree[i - 1], gcd), min(tree[i] - tree[i - 1], gcd));
			// cout << "changed gcd : " << gcd << "\n";
		}
	}

	// 사이에 심어야 하는 나무 개수를 구함
	ll cnt = 0;
	for (ll i = 2; i <= treeCNT; i++) {
		cnt += ((tree[i] - tree[i - 1]) / gcd) - 1;
	}

	cout << cnt;

	return 0;
}