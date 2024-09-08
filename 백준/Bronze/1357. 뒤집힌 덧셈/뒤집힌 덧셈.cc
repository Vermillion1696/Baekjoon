#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	// a, b 뒤집기
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	// a + b
	int num = stoi(a) + stoi(b);
	
	// a + b 뒤집기
	string num_string = to_string(num);
	reverse(num_string.begin(), num_string.end());

	cout << stoi(num_string);
}