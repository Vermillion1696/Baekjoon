#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	string str;
	cin >> str;

	// 입력
	bool is_exist_zero = false;
	vector<int> v;
	for (int i = 0; str[i] != NULL; i++) {
		v.push_back(str[i] - '0');

		if (str[i] - '0' == 0) is_exist_zero = true;
	}

	// 맨 뒤 두 자리 빼고 정렬
	sort(v.begin(), v.end(), compare);

	int v_size = v.size();
	int digit_sum = 0;
	for (int i = 0; i < v_size; i++) {
		digit_sum += v[i];
	}

	// 출력
	if (!is_exist_zero || digit_sum % 3 != 0) {
		cout << -1;
	}
	else {
		for (auto iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter;
		}
	}
	return 0;
}