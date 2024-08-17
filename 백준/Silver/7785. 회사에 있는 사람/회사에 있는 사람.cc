#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast_output;

	set<string> str_set;
	string str, enter;
	bool is_enter;
	int command_cnt;
	cin >> command_cnt;

	while (command_cnt--) {
		cin >> str >> enter;

		// enter면 1, 아니면 0
		enter == "enter" ? is_enter = true : is_enter = false;

		if (is_enter) str_set.insert(str);
		else str_set.erase(str);
	}

	// rbegin(), rend()를 사용해 역순으로 출력
	auto iterator = str_set.rbegin();
	while (iterator != str_set.rend()) {
		cout << *iterator << "\n";
		iterator++;
	}

	return 0;
}