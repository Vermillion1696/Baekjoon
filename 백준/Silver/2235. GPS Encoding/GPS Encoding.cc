#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> dict;

// 사전 순서 세팅
void dict_set(string str) {
	dict.clear();
	for (int i = 0; i < str.length(); i++) {
		dict.push_back(str[i]);
	}
	return;
}

// 더 나은 문자열인가?
// 조건1. 길이가 더 짧아야 한다.
// 조건2. 길이가 같으면 사전순으로 뒤에 있어야 한다.
bool isBetter(const string& a, const string& b) {
	if (a.size() == b.size()) return a > b;
	return a.size() < b.size();
}

int main() {
	string dict_str, dp_str;
	
	for (int problem_num = 1; ; problem_num++) {
		cin >> dict_str;
		if (dict_str == "#") break;

		cout << "Problem " << problem_num << '\n';
		dict_set(dict_str);

		while (true) {
			cin >> dp_str;
			if (dp_str == "0") {
				cout << '\n';
				break;
			}

			int dp_size = dp_str.size();
			vector<string> dp(dp_size + 1, "-");
			dp[0] = "";

			for (int j = 0; j < dp_size; j++) {

				if (dp[j] != "-") {

					// 한 자릿수 처리
					int val = dp_str[j] - '0';

					// val > 25 이면 사전에 없는 값
					if (val >= 0 && val <= 25) {
						string new_str = dp[j] + dict[val];
						if (dp[j + 1] == "-" || isBetter(new_str, dp[j + 1])) {
							dp[j + 1] = new_str;
						}
					}

					// 두 자릿수 처리
					if (j + 1 < dp_size) {
						int val = stoi(dp_str.substr(j, 2));
						if (val >= 0 && val <= 25) {
							string new_str = dp[j] + dict[val];
							if (dp[j + 2] == "-" || isBetter(new_str, dp[j + 2])) {
								dp[j + 2] = new_str;
							}
						}
					}
				}
			}

			cout << dp[dp_size] << '\n';
		}
	}

	return 0;
}