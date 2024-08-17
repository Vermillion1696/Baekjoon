#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string str;

// 세 자리 2진수 숫자를 문자열로 받으면 한 자리 8진수 숫자를 출력
void str_to_octal(const string& substr) {
	int return_num = 0, adjust;
	for (int i = 2; i >= 0; i--) {
		if (i == 0) adjust = 4;
		else if (i == 1) adjust = 2;
		else adjust = 1;
		return_num += (substr[i] - '0') * adjust;
	}

	cout << return_num;
	
	return;
}

int main() {
	cin >> str;
	int str_size = str.size();
	
	// 맨 앞 자리 생략된 0 채우기
	if (str_size % 3 == 1) str = "00" + str;
	else if (str_size % 3 == 2) str = "0" + str;

	str_size = str.size();

	string substr = "";
	for (int i = 0; i < str_size; i++) {
		substr += str[i];

		// substr의 길이가 3이 되면
		if (i % 3 == 2) {
			str_to_octal(substr);
			substr = "";
		}
	}

	return 0;
}