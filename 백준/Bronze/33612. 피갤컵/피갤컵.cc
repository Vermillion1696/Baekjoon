#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	switch (n) {
	case 1:
		cout << "2024 8"; break;
	case 2:
		cout << "2025 3"; break;
	case 3:
		cout << "2025 10"; break;
	case 4:
		cout << "2026 5"; break;
	case 5:
		cout << "2026 12"; break;
	default:
		cout << "err";
	}

	return 0;
}