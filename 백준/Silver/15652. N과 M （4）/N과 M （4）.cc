#include <iostream>
using namespace std;

// sequence : 실제 출력 순열
int n, m;
int sequence[10];


void func(int k) {
	
	// k는 현재 사용된 개수를 의미
	// k == m이면 모든 수열의 숫자가 정해진 때
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
	}
	else {

		// 비내림차순
		int dir;
		k == 0 ? dir = 1 : dir = sequence[k - 1];

		for (int i = dir; i <= n; i++) {

			// k번째 숫자는 i, i는 사용됨 처리
			sequence[k] = i;

			// k + 1번째 숫자를 찾음
			func(k + 1);

		}
	}

	return;
}

int main() {
	cin >> n >> m;

	func(0);

	return 0;
}