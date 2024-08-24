#include <iostream>
using namespace std;

// sequence : 실제 출력 순열
// is_used : i번째 index 숫자가 사용 되었는지 여부
int n, m;
int sequence[10];
bool is_used[10];


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

		// 다음에 오는 숫자는 이전 숫자보다 커야 함
		int dir;
		k == 0 ? dir = 1 : dir = sequence[k - 1];

		for (int i = dir; i <= n; i++) {
			
			// 1부터 n까지 중 사용되지 않은 숫자를 찾음
			if (!is_used[i]) {

				// k번째 숫자는 i, i는 사용됨 처리
				sequence[k] = i;
				is_used[i] = true;
			
				// k + 1번째 숫자를 찾음
				func(k + 1);

				// i는 사용되지 않음 처리
				is_used[i] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> n >> m;

	func(0);

	return 0;
}