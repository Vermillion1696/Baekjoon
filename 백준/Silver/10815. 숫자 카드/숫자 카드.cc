#include <iostream>
#include <set>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast_output;

	set<int> my_set;
	int card_cnt, value;
	cin >> card_cnt;

	// 삽입
	while (card_cnt--) {
		cin >> value;
		my_set.insert(value);
	}

	int quest;
	cin >> quest;
	
	while (quest--) {
		cin >> value;

		// find는 iterator를 반환
		auto iter = my_set.find(value);
		iter != my_set.end() ? cout << 1 : cout << 0;
		cout << " ";
	}

	return 0;
}