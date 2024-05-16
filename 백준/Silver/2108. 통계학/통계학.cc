#include <iostream>
#include <algorithm> // sort function
#include <cmath> // round function
#include <queue> // queue
using namespace std;

int arr[500000];
int cnt[8001] = { 0, };
// 0~3999 : -4000 ~ -1, 4000 : 0, 4001~8000 : 1 ~ 4000

int main() {
	int n;
	cin >> n;

	// arr : 실제 값 배열, cnt : -4000~4000까지 몇 번 나왔는지 저장 배열
	double total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
		cnt[4000 + arr[i]]++;
	}

	// 정렬
	sort(arr, arr + n);

	// 산술평균, 중앙값, 최빈값, 범위
	int arithmeticMean, median, mode, range;

	// 산술평균 : 합/개수 반올림, 중앙값 : n / 2 번째 원소
	arithmeticMean = round(total / n);
	median = arr[n / 2];

	// 가장 많이 나온 "횟수" 찾기
	int max = -1;
	for (int i = 0; i <= 8000; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
		}
	}

	// 찾은 횟수 만큼 나온 "숫자" queue에 넣기
	queue<int> q;
	for (int i = 0; i <= 8000; i++) {
		if (cnt[i] == max) {
			q.push(i - 4000);
		}
	}

	// 1개면 그냥 출력, 2개 이상이면 제일 작은거 빼고 두 번째꺼 출력
	if (q.size() == 1) {
		mode = q.front();
	}
	else {
		q.pop();
		mode = q.front();
	}
	
	// 범위 : 맨 끝 - 맨 앞
	range = arr[n - 1] - arr[0];

	cout << arithmeticMean << "\n" << median << "\n" << mode << "\n" << range;
	
	return 0;
}