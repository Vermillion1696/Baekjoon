#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// 나머지 연산자를 이용한 사이클 구현
	if (n % 8 == 1) {
		cout << 1;
	}
	else if (n % 8 == 5) {
		cout << 5;
	}
	else if (n % 8 == 2 || n % 8 == 0) {
		cout << 2;
	}
	else if (n % 8 == 3 || n % 8 == 7) {
		cout << 3;
	}
	else {
		cout << 4;
	}

	return 0;
}