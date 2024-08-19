#include <iostream>
using namespace std;

int main() {
	string str;
	int n;
	cin >> n >> str;
	
	// c의 개수, c가 아닌 개수 세기
	int c = 0, not_c = 0, str_size = str.size();
	for (int i = 0; i < str_size; i++) {
		if (str[i] == 'C') c++;
		else not_c++;
	}
	
	// n일을 not_c + 1 조각으로 나눔
	cout << n / (not_c + 1);
}