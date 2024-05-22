#include <iostream>
#include <algorithm>
using namespace std;

// i+1 를 1로 만드는 데 필요한 최소 횟수 arr[i]
int arr[1000000];

int main() {
	int n;
	cin >> n;

	// n을 1로 만드는 데 필요한 횟수를 구할 때까지
	for (int i = 2; i <= n; i++) {

		// case 1. 1을 빼는 경우
		arr[i] = arr[i - 1] + 1;

		// case 2. 3으로 나누어 떨어지는 경우
		// i-1까지 걸린 횟수 vs i/3까지 걸린 횟수 + 1
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}

		// case 3. 2로 나누어 떨어지는 경우
		// i-1까지 걸린 횟수 vs i/2까지 걸린 횟수 + 1
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
	}
	// -> 결국 1, 2, 3 선택지 모두를 비교하게 된다

	// 출력
	cout << arr[n];

	return 0;
}