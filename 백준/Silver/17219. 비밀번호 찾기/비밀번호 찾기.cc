#include <iostream>
#include <unordered_map>
#include <utility>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
#define site first
#define pass second
using namespace std;

int main() {
	fast_output;

	unordered_map<string, string> un_map;
	pair<string, string> set;
	string str;

	int site_num, question_num;
	cin >> site_num >> question_num;

	while (site_num--) {
		cin >> set.site >> set.pass;
		un_map.insert(set);
	}

	while (question_num--) {
		cin >> str;

		// find는 원하는 요소를 찾았을 때 iterator를 반환
		cout << un_map.find(str)->pass << "\n";
	}

	return 0;
}