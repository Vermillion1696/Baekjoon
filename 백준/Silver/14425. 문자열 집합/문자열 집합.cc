#include <iostream>
#include <set>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast_output;

	set<string> str_set;
	string str;
	int set_str_cnt, str_cnt;
	cin >> set_str_cnt >> str_cnt;

	while (set_str_cnt--) {
		cin >> str;
		str_set.insert(str);
	}

	int cnt = 0;
	auto iterator = str_set.begin();
	while (str_cnt--) {
		cin >> str;
		iterator = str_set.find(str);
		if (iterator != str_set.end()) cnt++;
	}

	cout << cnt;

	return 0;
}