#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> prime;

// deque에 1,500,000까지의 소수를 다 넣음
void primeSET() {
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5; i <= 1500000; i += 2) {
		int size = prime.size();
		bool isPrime = true;
		for (int j = 0; j < size; j++) {
			if (i % prime[j] == 0) {
				isPrime = false;
				break;
			}
			if (prime[j] * prime[j] > i) break;
		}

		if (isPrime) prime.push_back(i);
	}
	
	return;
}

// 팰린드롬인지 판별하는 함수
bool isPalindrome(const int& n) {
	string str = to_string(n);

	int size = str.size();
	for (int i = 0; i <= size / 2; i++) {
		if (str[i] != str[size - 1 - i]) return false;
	}

	return true;
}

int main() {

	// 초기 세팅
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	primeSET();
	int n;
	cin >> n;

	// 소수면서 팰린드롬이면 출력, 팰린드롬이 아니면 pop
	int size = prime.size();
	while (1) {
		if (prime.front() >= n && isPalindrome(prime.front())) {
			cout << prime.front();
			break;
		}
		else {
			prime.pop_front();
		}
	}

	return 0;
}