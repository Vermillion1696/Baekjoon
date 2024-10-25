#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;

static bool ischar(const char c) {
	if ('A' <= c && c <= 'Z') return true;
	else return false;
}

static bool isoperator(const char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return true;
	else return false;
}

static double calculate(const double first, const char op, const double second) {
	if (op == '+') return first + second;
	else if (op == '-') return first - second;
	else if (op == '*') return first * second;
	else return first / second;
}

int main() {

	vector<pair<char, int>> v(26);
	for (int idx = 0; idx < 26; idx++) {
		v[idx].first = 'A' + idx;
	}

	int op;
	cin >> op;

	string str;
	cin >> str;

	for (int i = 0; i < op; i++) {
		cin >> v[i].second;
	}

	stack<double> s;
	for (int idx = 0; str[idx] != NULL; idx++) {
		if (ischar(str[idx])) {
			int gap = str[idx] - 'A';
			s.push(v[gap].second);
		}
		else {
			double first = s.top();
			s.pop();
			double second = s.top();
			s.pop();

			s.push(calculate(second, str[idx], first));
		}
	}

	cout << fixed << setprecision(2) << s.top();

	return 0;
}