#include <iostream>
#include <set>
#define a first
#define b second
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

// A 집합, 대칭차집합 집합
pair<set<int>, set<int>> u;
int total_cnt = 0;

// A - B 의 원소 개수
void cnt_checker(const set<int>& A, const set<int>& B) {

	// iter_a는 A의 원소를 하나씩 살펴봄
	auto iter_a = A.begin();
	while (iter_a != A.end()) {

		// iter_a가 A의 특정 원소를 가리키고 있는 동안 (*iter_a)
		// iter_b는 B를 순회하며 *iter_a와 동일한 원소가 없는 지 확인
		// -> total_cnt++;
		auto iter_b = B.find(*iter_a);
		if (iter_b == B.end()) total_cnt++;
		
		iter_a++;
	}

	return;
}

int main() {
	fast_output;

	int a_cnt, b_cnt, value;
	cin >> a_cnt >> b_cnt;

	while (a_cnt--) {
		cin >> value;
		u.a.insert(value);
	}

	while (b_cnt--) {
		cin >> value;
		u.b.insert(value);
	}

	cnt_checker(u.a, u.b);
	cnt_checker(u.b, u.a);

	cout << total_cnt;

	return 0;
}