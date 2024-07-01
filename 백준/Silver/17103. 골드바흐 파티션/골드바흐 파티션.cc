#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001
bool isPrime[MAX];
vector<int> prime;

// MAX까지의 소수들을 vector prime에 담음
void primeSET() {
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5; i < MAX; i += 2) {
		bool isPrime = true;
		for (int j = 1; j < prime.size(); j++) {
			if (i % prime[j] == 0) {
				isPrime = false;
				break;
			}
			if (prime[j] * prime[j] > i) {
				break;
			}
		}

		if (isPrime) {
			prime.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc, n;
	cin >> tc;

	primeSET();
	int size = prime.size();
	for (int i = 0; i < size; i++) {
		isPrime[prime[i]] = true;
	}

	
	while (tc--) {
		cin >> n;

		int cnt = 0;
		for (int k = 0; k < MAX; k++) {
			if ((n / 2) - k < 0) break;
			if (isPrime[(n / 2) + k] && isPrime[(n / 2) - k]) cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}