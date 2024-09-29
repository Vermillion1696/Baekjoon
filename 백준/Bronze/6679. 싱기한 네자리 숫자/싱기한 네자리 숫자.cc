#include <iostream>
#include <vector>
using namespace std;

vector<int> remaker(int num, int div) {

	vector<int> v;

	do {
		v.push_back(num % div);
		num /= div;
	} while (num / div > 0);
	v.push_back(num);

	return v;
}

bool isSame(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
	
	int v1s = 0;
	while (!v1.empty()) {
		v1s += v1.back();
		v1.pop_back();
	}

	int v2s = 0;
	while (!v2.empty()) {
		v2s += v2.back();
		v2.pop_back();
	}

	int v3s = 0;
	while (!v3.empty()) {
		v3s += v3.back();
		v3.pop_back();
	}

	return (v1s == v2s && v2s == v3s);
}

int main() {

	vector<int> list;

	for (int i = 1000; i < 10000; i++) {
		vector<int> ten = remaker(i, 10);
		vector<int> twelve = remaker(i, 12);
		vector<int> sixteen = remaker(i, 16);

		if (isSame(ten, twelve, sixteen)) {
			list.push_back(i);
		}
	}

	for (auto iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}