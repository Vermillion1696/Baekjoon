#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	// string deque
	deque<string> deut, bo;

	// 각 deque 원소 수
	int n, m;
	cin >> n >> m;

	// 입력
	string temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		deut.push_front(temp);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		bo.push_front(temp);
	}

	// 정렬
	sort(deut.begin(), deut.end());
	sort(bo.begin(), bo.end());
	
	// vector v는 동일한게 들어있으면 넣는다
	int cnt = 0;
	vector<string> v;
	while (deut.size() != 0 && bo.size() != 0) {
		// 같으면 넣기
		if (deut.back().compare(bo.back()) == 0) {
			v.push_back(deut.back());
			deut.pop_back();
			bo.pop_back();
			cnt++;
		}
		// 다르면 사전이 빠른 순인걸 빼기 (정렬 되어 있으므로)
		else {
			if (deut.back().compare(bo.back()) > 0) {
				deut.pop_back();
			}
			else {
				bo.pop_back();
			}
		}
	}

	cout << cnt << "\n";
	for (int i = cnt - 1; i >= 0; i--) {
		cout << v[i] << "\n";
	}

	return 0;
}