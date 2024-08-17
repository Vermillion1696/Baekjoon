#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
#define kind first
#define name second
using namespace std;

int main() {
	fast_output;
	
	int tc;
	cin >> tc;

	while (tc--) {
		// 종류, 이름
		unordered_map<string, vector<string>> un_map;
		pair<string, string> value;
		vector<string> v_str = {};

		int wear;
		cin >> wear;
		while (wear--) {
			cin >> value.name >> value.kind;

			auto iterator = un_map.find(value.kind);

			// 동일한 종류가 없으면 종류 vector를 insert();
			if (iterator == un_map.end()) {
				v_str.push_back(value.name);
				un_map.insert({ value.kind, v_str });
				v_str.pop_back();
			}
			// 동일한 종류가 있으면 종류 vector에 push_back();
			else {
				iterator->second.push_back(value.name);
			}
		}

		// 알몸이 아니다 -> 모든 종류중 적어도 하나는 입는다
		// ex. 2 1 (개수) -> (2 + 1) * (1 + 1) - 1 (조합) = 5
		int permutation = 1;
		auto iterator = un_map.begin();
		for (iterator = un_map.begin(); iterator != un_map.end(); iterator++) {
			permutation *= iterator->name.size() + 1;
		}
		permutation--;

		cout << permutation << "\n";
	}

	return 0;
}