#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// <algorithm> 내장 sort 함수 인자 compare()
int compare(int a, int b) {
	return a > b;
}

int main() {

	// 문자열 입력
	string str;
	cin >> str;

	// 문자열 -> 정수 배열 전환
	int arr[10];
	for (int i = 0; str[i] != NULL; i++) {
		arr[str.length() - i - 1] = str[i] - '0';
	}

	// 정렬
	sort(arr, arr + str.length(), compare);

	// 출력
	for (int i = 0; i < str.length(); i++) {
		cout << arr[i];
	}

	return 0;
}