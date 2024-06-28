#include <iostream>
using namespace std;
// 1 그룹과 0 그룹을 세고 비교 -> 작은 것 출력

int main() {
	string str;
	cin >> str;

	// 첫 세팅
	int cnt1 = 0, cnt0 = 0;
	bool before = str[0] - '0';
	before == 1 ? cnt1++ : cnt0++;

	for (int i = 1; str[i] != NULL; i++) {
		int number = str[i] - '0';

		// 이전 숫자와 현재 숫자가 다르면
		if (before != number) {
			number == 1 ? cnt1++ : cnt0++;
			before = number;
		}
	}

	cnt1 > cnt0 ? cout << cnt0 : cout << cnt1;
	
	return 0;
}