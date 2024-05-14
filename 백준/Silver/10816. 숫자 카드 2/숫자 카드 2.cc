#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

// 비교 함수
bool compare(int a, int b) {
	return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	// n개의 정수를 vector에 쌓음
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	// 정렬
	sort(v.begin(), v.end(), compare);

	// upper_bound - lower_bound
	// upper_bound : 주어진 n보다 큰 값이 처음으로 등장한 위치 반환
	// lower_bound : 주어진 n보다 작은 값이 처음으로 등장한 위치 반환
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
	}

	return 0;
}