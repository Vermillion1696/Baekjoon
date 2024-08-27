#include <iostream>
using namespace std;
int cnt = 0, n;

// 열 위치에 따른 퀸 가능 여부
bool is_used_y[500];

// 왼쪽 위 대각선 위치에 따른 퀸 가능 여부
bool is_used_x_plus_y[500];

// 오른쪽 아래 대각선 위치에 따른 퀸 가능 여부
bool is_used_x_minus_y[500];

void n_queen(int cur) {
	
	if (cur == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (is_used_y[i] || is_used_x_plus_y[i + cur] || is_used_x_minus_y[cur - i + n - 1]) {
				continue;
			}

			// n - 1 보정 : 인덱스가 음수가 되지 않기 위함

			is_used_y[i] = true;
			is_used_x_plus_y[cur + i] = true;
			is_used_x_minus_y[cur - i + n - 1] = true;

			n_queen(cur + 1);

			is_used_y[i] = false;
			is_used_x_plus_y[cur + i] = false;
			is_used_x_minus_y[cur - i + n - 1] = false;
		}
	}
	
	return;
}


int main() {
	cin >> n;

	n_queen(0);

	cout << cnt;
}