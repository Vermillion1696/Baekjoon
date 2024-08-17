#include <iostream>
#include <set>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int subset_str_cnt = 0, original_str_size;
string original_str, str;

void subset_str_checker(const int& cut_size) {
	set<string> subset_str;

	// cut_size : 부분 문자열의 길이
	// start_index : 전체 문자열에서 부분 문자열의 시작 index
	for (int start_index = 0; start_index <= original_str_size - cut_size; start_index++) {
		str = "";

		// 부분 문자열을 조합
		for (int i = 0; i < cut_size; i++) {
			str += original_str[start_index + i];
		}

		// 부분 문자열이 없으면 부분 문자열 집합에 넣고 개수 증가
		auto iterator = subset_str.find(str);
		if (iterator == subset_str.end()) {
			subset_str_cnt++;
			subset_str.insert(str);
		}
	}

	return;
}

int main() {
	fast_output;

	cin >> original_str;
	original_str_size = original_str.size();

	// cut_size : 얼마의 길이로 부분 문자열을 자를 건지
	for (int cut_size = 1; cut_size <= original_str_size; cut_size++) {
		subset_str_checker(cut_size);
	}

	cout << subset_str_cnt;
}