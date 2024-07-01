#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MAX 300000
vector<int> prime;
int primeSUM[MAX];

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

	primeSET();

	// prefix sum
	// 현재 소수 ~ 다음 소수 - 1 까지는 소수의 개수가 cnt
	// 다음 소수 ~ 다다음 소수 - 1 까지는 소수의 개수가 cnt + 1
	// ... , 미리 합을 저장한다
	int cnt = 1;
	for (int i = 0; i < prime.size() - 1; i++) {
		for (int j = prime[i]; j <= prime[i + 1] - 1; j++) {
			primeSUM[j] = cnt;
		}
		cnt++;
	}

	int n;
	while (1) {
		cin >> n;
		
		if (n == 0) return 0;

		// n보다 크고 2n보다 작거나 같은 소수의 개수는
		// 2n까지의 소수 합 - n까지의 소수 합 이다
		cout << primeSUM[2 * n] - primeSUM[n] << "\n";
	}
}