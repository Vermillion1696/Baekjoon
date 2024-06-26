#include <iostream>
using namespace std;
int x, y;

// 움직임 출력
void move(const int a, const int b) {
	cout << a << " " << b << "\n";
	return;
}

// (1) : Base
// (1)2(1)
// (121)3(121)
// (1213121)4(1213121)
// ...
void hanoi(int n, int x, int y, int z) {
	if (n > 0) {
		hanoi(n - 1, x, z, y);
		move(x, y);
		hanoi(n - 1, z, y, x);
	}
	return;
}

int main() {
	int n;
	long long int total = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		total *= 2;
	}

	cout << total - 1 << endl;
	hanoi(n, 1, 3, 2);
}