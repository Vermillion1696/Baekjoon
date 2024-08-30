#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;

void func(int cur, int tot) {

	// 탈출 조건 (현재 길이가 n일 때)
	if (cur == n) {

		// tot와 값이 같으면 합이 s가 되는 부분수열
		if (tot == s) {
			cnt++;
		}
		return;
	}

	// func(cur+1, tot)은 arr[cur]을 더하지 않은 세계관
	func(cur + 1, tot);

	// func(cur+1, tot+arr[cur])은 arr[cur]을 더한 세계관
	func(cur + 1, tot + arr[cur]);

	return;
}

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);

	// 공집합은 세지 않으므로, 공집합이 cnt에 들어가는 경우인 s == 0 일때 cnt--
	if (s == 0) cnt--;
	cout << cnt;
}