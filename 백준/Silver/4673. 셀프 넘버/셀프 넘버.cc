#include <iostream>
#include <vector>
using namespace std;
bool visited[10001];

int constructor(int n) {
	vector<int> v = { n };
	int total = 0;

	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	while (!v.empty()) {
		total += v.back();
		v.pop_back();
	}

	return total;
}

int main() {
	
	int nextNUM;
	for (int i = 1; i <= 10000; i++) {
		nextNUM = i;
		while (!visited[constructor(nextNUM)]) {
			visited[constructor(nextNUM)] = true;
			nextNUM = constructor(nextNUM);

			if (nextNUM > 10000) {
				break;
			}
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (!visited[i]) {
			cout << i << "\n";
		}
	}
	
	return 0;
}