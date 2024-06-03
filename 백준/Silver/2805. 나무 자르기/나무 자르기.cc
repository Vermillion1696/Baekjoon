#include <iostream>
#include <vector>
using namespace std;

// vector의 elements중 최댓값을 반환
long long int maximum(vector<long long int>& v) {
	long long int max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

// target의 높이로 잘랐을 때 나무 길이의 sum을 반환
long long int cut(vector<long long int>& v, long long int& height) {
	long long int total = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > height) {
			total += v[i] - height;
		}
	}
	return total;
}

// 이진 탐색
long long int binarySearch(vector<long long int>& v, long long int target, long long int left, long long int right) {

	if (left > right) {
		return right;
	}

	long long int mid = (left + right) / 2;

	// result : 자른 나무 길이의 sum
	long long int result = cut(v, mid);

	// 동일하면 반환
	if (result == target) {
		return mid;
	}
	// 더 많이 잘랐으면 높이를 높여서
	else if (result > target) {
		return binarySearch(v, target, mid + 1, right);
	}
	// 더 적게 잘랐으면 높이를 낮춰서
	else {
		return binarySearch(v, target, left, mid - 1);
	}
}

int main() {
	long long int tree, meter;
	cin >> tree >> meter;
	vector<long long int> v;

	// 입력
	long long int height;
	while (tree--) {
		cin >> height;
		v.push_back(height);
	}

	// 최댓값 찾기
	long long int max = maximum(v);

	// 시작은 0, max로 -> 출력
	cout << binarySearch(v, meter, 0, max);

	return 0;
}