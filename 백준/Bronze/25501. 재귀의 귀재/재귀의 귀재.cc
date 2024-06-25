#include <iostream>
#include <string>
using namespace std;

// 팰린드롬 판별 함수 (리턴 : 재귀일때 호출횟수 - 1, 재귀 사용 X)
int Palindrome(string& str, bool& isPalindrome) {
	int mid = str.length() / 2;
	int length = str.length();
	int cnt = 0;

	// 양 끝 부터 가운데까지 점점 검사
	for (int i = 0; i < mid; i++) {
		if (str[i] != str[length - 1 - i]) {
			isPalindrome = false;
			return cnt;
		}
		else {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int tc;
	bool isPalindrome;
	cin >> tc;

	string str;
	while (tc--) {
		isPalindrome = true;
		cin >> str;

		int cnt = Palindrome(str, isPalindrome);
		cout << isPalindrome << " " << cnt + 1 << "\n";
	}
	
	return 0;
}