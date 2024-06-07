#include <iostream>
#include <vector>
using namespace std;

// 맥시멈 반환이 2^31-1 이므로 long long 형 반환 거듭제곱 함수 pow를 만듦
long long int pow(int a, int b) {
	long long int total = 1;
	while (b--) {
		total *= a;
	}
	return total;
}

int main() {
	long long int total = 0;
	int x, y;
	vector<bool> v;
	cin >> x >> y;

	// 2로 나눈 나머지 (이진수 비트)를 벡터에 저장
	for (int i = 0; i < 16; i++) {
		v.push_back(x % 2);
		x /= 2;
	}

	// x는 2^31부터 2^1까지 -= 2씩 내려감
	for (int i = 31; i >= 1; i -= 2) {
		if (v.back() == 1) {
			total += pow(2, i);
		}
		v.pop_back();
	}

	// y도 마찬가지
	for (int i = 0; i < 16; i++) {
		v.push_back(y % 2);
		y /= 2;
	}

	// y는 2^30부터 2^0까지 -= 2씩 내려감
	for (int i = 30; i >= 0; i -= 2) {
		if (v.back() == 1) {
			total += pow(2, i);
		}
		v.pop_back();
	}

	cout << total;
	
	return 0;
}