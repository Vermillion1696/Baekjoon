#include <iostream>
#include <queue>
using namespace std;

int main() {
	string names[5];
	for (int i = 0; i < 5; i++) cin >> names[i];

	queue<int> q;
	for (int i = 0; i < 5; i++) {
		if (names[i].find("FBI") != string::npos) q.push(i + 1);
	}

	if (!q.empty()) {
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
	}
	else {
		cout << "HE GOT AWAY!";
	}
}