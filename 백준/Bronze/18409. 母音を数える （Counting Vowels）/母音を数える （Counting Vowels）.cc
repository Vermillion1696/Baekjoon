#include <iostream>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}