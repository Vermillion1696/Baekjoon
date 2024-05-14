#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 1~10000까지 몇 번이 나왔는지 저장할 배열
	int arr[10000] = { 0, };

	int n;
	cin >> n;

	// 배열의 index는 숫자를 의미
	int temp;
	while (n--) {
		cin >> temp;
		arr[temp - 1]++;
	}
	
	// 배열에 저장된 값 (숫자가 나온 횟수)가 0이 아니면 출력
	for (int i = 0; i < 10000; i++) {
		while (arr[i] != 0) {
			cout << i + 1 << "\n";
			arr[i]--;
		}
	}

	return 0;
}