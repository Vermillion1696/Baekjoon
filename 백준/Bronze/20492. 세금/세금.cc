#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;

	cout << int(n * 0.78) << endl;
	
	long long int temp = n * 0.8;
	n *= 0.2;
	n *= 0.78;

	cout << temp + n << endl;

	return 0;
}