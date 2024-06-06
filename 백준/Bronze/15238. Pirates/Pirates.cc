#include <iostream>
using namespace std;

int main() {
	int alphabet[26] = { 0, };
	int n;
	string str;
	cin >> n >> str;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == 'a' + j) {
				alphabet[j]++;
			}
		}
	}

	int max = -1;
	char letter = 'a';
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
			letter = i + 'a';
		}
	}

	cout << letter << " " << max;

	return 0;
}