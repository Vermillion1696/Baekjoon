#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n1, n2;
	cin >> n1 >> n2;
	vector<int> fibo = { n1, n2 };
	
	int cur, cnt = 2;
	while (true) {
		
		// 다음 숫자
		cur = (n1 + n2) % 10;

		// 완료시 n1은 n2, n2는 cur, cur는 n1이 들어가있음
		// 즉, {n2, cur} == 원래 {n1, n2}를 만족 시키는지 비교만 하면 된다
		swap(n1, n2);
		swap(n2, cur);

		cnt++;

		if (n1 == fibo[0] && n2 == fibo[1]) break;
	}

	cout << cnt;

	return 0;
}