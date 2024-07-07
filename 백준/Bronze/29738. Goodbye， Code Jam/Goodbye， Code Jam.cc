#include <iostream>
using namespace std;

int main() {
	int tc, rank;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		cin >> rank;

		cout << "Case #" << i << ": ";
		if (rank <= 25) cout << "World Finals\n";
		else if (rank <= 1000) cout << "Round 3\n";
		else if (rank <= 4500) cout << "Round 2\n";
		else cout << "Round 1\n";
	}

	return 0;
}