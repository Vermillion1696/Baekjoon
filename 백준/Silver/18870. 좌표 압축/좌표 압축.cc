#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	// 중복 제거 벡터 v1, 원 벡터 v2
	vector<int> v1, v2;
	int n, number;
	cin >> n;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> number;
		v1.push_back(number);
		v2.push_back(number);
	}

	// 정렬 후 v1 중복 제거
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	
	// v2[i]의 v1 내부 index를 반환
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << " ";
	}
	
	return 0;
}