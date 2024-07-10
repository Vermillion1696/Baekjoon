#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int size = str.size();
	for (int i = 0; i < size; i++) {

		cout << str[i];

		// 10번째 글자면 줄바꿈 출력
		if ((i + 1) % 10 == 0) {
			cout << "\n";
		}
	}

	return 0;
}