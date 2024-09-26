#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

string question[10] = { "ABCDEFGHJLM","ACEFGHILM","ACEFGHILM","ABCEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ABCFGHLM" };
int counts[10] = { 11, 9, 9, 9, 8, 8, 8, 8, 8, 8 };

int main() {
	int n;
	cin >> n;

	cout << counts[n - 1] << '\n';
	for (int i = 0; i < question[n - 1].length(); i++) {
		cout << question[n - 1][i] << ' ';
	}

	return 0;
}