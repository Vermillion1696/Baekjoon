#include <iostream>
#include <cmath>
using namespace std;
// 주석 : #13909 와 완전히 동일한 코드로 맞을 수 있다.

// 창문을 친 횟수가 "홀수" 여야 마지막 상태가 1이다
// -> 약수의 개수가 "홀수" 여야 마지막 상태가 1이다
// -> "겹치는 약수가 있어야" 마지막 상태가 1이다
// -> n은 제곱수이다

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
	}
	else {
		for (long long int i = 1; i <= 1000000000; i++) {
			if (i * i <= (n) && (i + 1) * (i + 1) > (n)) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}