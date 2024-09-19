#include <iostream>
using namespace std;

// arr : 실제 배열
// cont : 현재까지 연속하는 개수
// ex. 
// cont[n][ascend] = n번째까지 오름차순 개수
// cont[n][descend] = n번째까지 내림차순 개수
constexpr int ascend = 0;
constexpr int descend = 1;
int arr[100000];
int cont[100000][2];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cont[0][ascend] = 1;
	cont[0][descend] = 1;
	for (int i = 1; i < n; i++) {
		// 오름차순
		if (arr[i - 1] < arr[i]) {
			cont[i][ascend] = cont[i - 1][ascend] + 1;
			cont[i][descend] = 1;
		}
		// 내림차순
		else if (arr[i - 1] > arr[i]) {
			cont[i][ascend] = 1;
			cont[i][descend] = cont[i - 1][descend] + 1;
		}
		// 같은경우
		else {
			cont[i][ascend] = cont[i - 1][ascend] + 1;
			cont[i][descend] = cont[i - 1][descend] + 1;
		}
	}

	int max_cnt = 1;
	for (int i = 0; i < n; i++) {
		max_cnt = max(max_cnt, max(cont[i][ascend], cont[i][descend]));
	}

	cout << max_cnt;
}