#include <iostream>
#include <set>
using namespace std;

int main() {

	// 입력
	set<int> s;
	int a_cnt, b_cnt;
	cin >> a_cnt >> b_cnt;

	int value;

	// A에 해당하는 원소를 우선 set에 넣음
	while (a_cnt--) {
		cin >> value;
		s.insert(value);
	}

	// B에 해당하는 원소가 set에 있으면 제거
	while (b_cnt--) {
		cin >> value;
		s.erase(value);
	}

	// 출력
	if (s.empty()) cout << 0;
	else {
		cout << s.size() << '\n';
		for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << ' ';
	}

	return 0;
}