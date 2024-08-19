#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

// 커스텀 비교 인자
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
    
    // 단어 입력
	while (words--) {
		cin >> str;
        
        // 단어 길이가 최소 길이보다 작으면 입력 X
		if (str.length() < min_length) continue;
		map[str]++;
	}
	
    // 벡터에 복사
	vector<pair<string, int>> v;
	for (auto iter = map.begin(); iter != map.end(); iter++) {
		v.push_back({ iter->first, iter->second });
	}
    
    // 기준에 맞게 정렬
	sort(v.begin(), v.end(), compare);

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << "\n";
	}

	return 0;
}