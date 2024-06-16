#include <iostream>
using namespace std;

int main() {
	int ppl, size[6], t, p;
	cin >> ppl;
	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}
	cin >> t >> p;

	// 사이즈 세트 개수
	int total = 0;
	for (int i = 0; i < 6; i++) {
		if (size[i] > t) {
			total += size[i] / t;
			size[i] %= t;
		}
		if (size[i] != 0) {
			total++;
		}
	}

	cout << total << "\n";
	cout << ppl / p << " " << ppl % p;

	return 0;
}