#include <iostream>
#include <algorithm>
using namespace std;
constexpr int MAX = 10001;
constexpr int NONE = -1;

// sequence : 실제 출력 순열
// num_list : 숫자 후보 배열
int n, m;
int sequence[10];
int num_list[10];
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

	// 마지막으로 사용한 숫자
	int last_used = NONE;

	for (int i = 1; i <= n; i++) {

		int cur_num = num_list[i];

		// 사용하지 않았고   중복이 아니며         수열의 첫 번째 숫자이거나 이전 수열 숫자보다 커야 함
		// !is_used[i]  &&   cur_num != last_used  (k == 0                || cur_num >= sequence[k - 1])
		if (!is_used[i] && cur_num != last_used && (k == 0 || cur_num >= sequence[k - 1])) {

			// k번째 숫자는 cur_num, i번째 숫자를 사용함으로 바꿈
			sequence[k] = cur_num;
			is_used[i] = true;

			// 마지막으로 사용한 숫자 갱신
			last_used = cur_num;

			// k + 1번째 숫자를 찾음
			func(k + 1);

			// i번째 숫자를 사용하지 않음으로 바꿈
			is_used[i] = false;

		}
	}

	return;
}

int main() {

	// num_list를 0번 index부터 9번 index까지 MAX로 채움
	fill(num_list, num_list + 10, MAX);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> num_list[i];

	// num_list를 1번 index부터 9번 index까지 정렬 (실제로 사용할 부분)
	sort(num_list + 1, num_list + 10);

	func(0);

	return 0;
}