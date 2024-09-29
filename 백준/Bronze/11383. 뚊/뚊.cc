#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	// 입력
	vector<string> pic;
	string str;
	int pic_cnt, len;
	cin >> pic_cnt >> len;
	
	for (int i = 0; i < pic_cnt * 2; i++) {
		cin >> str;
		pic.push_back(str);
	}
	
	bool eyfa = true;

	// 첫 이미지 : pic[i]
	// 2배 이미지 : pic[i+pic_cnt]
	for (int i = 0; i < pic_cnt; i++) {
		string str1 = pic[i];
		string str2 = pic[i + pic_cnt];

		for (int i = 0; i < str2.size(); i++) {
			if (str1[i / 2] != str2[i]) {
				eyfa = false;
				goto if_false_dir;
			}
		}
	}

if_false_dir:
	cout << (eyfa ? "Eyfa" : "Not Eyfa") << '\n';

	return 0;
}