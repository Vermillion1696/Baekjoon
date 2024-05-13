#include <iostream>
using namespace std;

int main() {
	int time;
	bool alcohol;
	cin >> time >> alcohol;

	if (time >= 12 && time <= 16 && !alcohol) {
		cout << "320";
	}
	else {
		cout << "280";
	}

	return 0;
}