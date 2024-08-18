#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
	return a.first < b.first;
}

int main() {
	
	unordered_map<string, int> map;
	string str;
	int words, min_length;
	cin >> words >> min_length;

	while (words--) {
		cin >> str;
		if (str.length() < min_length) continue;
		map[str]++;
	}
	
	vector<pair<string, int>> v;
	for (auto iter = map.begin(); iter != map.end(); iter++) {
		v.push_back({ iter->first, iter->second });
	}

	sort(v.begin(), v.end(), compare);

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << "\n";
	}

	return 0;
}