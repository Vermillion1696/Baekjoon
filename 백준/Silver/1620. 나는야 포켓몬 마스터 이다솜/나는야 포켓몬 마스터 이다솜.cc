#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> map_str;
	unordered_map<int, string> map_int;
	string str;
	int pokemon_cnt, question;
	cin >> pokemon_cnt >> question;

	for (int index = 1; index <= pokemon_cnt; index++) {
		cin >> str;
		map_str.insert({ str, index });
		map_int.insert({ index,str });
	}

	while (question--) {
		cin >> str;
		if (isdigit(str[0])) cout << map_int[stoi(str)] << "\n";
		else cout << map_str[str] << "\n";
	}
}