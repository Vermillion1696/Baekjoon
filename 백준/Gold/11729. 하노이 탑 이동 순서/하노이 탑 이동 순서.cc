#include <iostream>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

// 인자 순서 : 시작 위치, 옮길 위치, 경유 지점, 개수
void hanoi(int from, int to, int via, long long int cnt) {

	// 이동 개수가 1개인 경우
	if (cnt == 1) {
		cout << from << " " << to << "\n";
	}
	// 이동 개수가 1개 이상인 경우
	else {

		// cnt - 1개를 from -> via
		hanoi(from, via, to, cnt - 1);

		// 1개를 from -> to (제일 큰 것)
		cout << from << " " << to << "\n";

		// cnt - 1개를 via -> to
		hanoi(via, to, from, cnt - 1);

	}
}

int main() {
	fast_output;

	long long n;
	int x = 1, y = 2, z = 3;
	cin >> n;

	// 2^n - 1을 비트마스킹으로 표현
	cout << (1 << n) - 1 << "\n";
	if (n <= 20) hanoi(x, z, y, n);

	return 0;
}