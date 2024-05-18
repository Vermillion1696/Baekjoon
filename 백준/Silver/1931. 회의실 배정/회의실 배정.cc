#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 구조체 선언
typedef struct group {
	int start;
	int end;
} group;
group arr[100000];

// <algorithm> 내장 sort 인자 compare
bool compare(group a, group b) {
	if (a.end != b.end) {
		return a.end < b.end;
	}
	else {
		return a.start < b.start;
	}
}

int main() {
	// 개수, pair stack s
	int n;
	cin >> n;
	stack<pair<int, int>> s;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}

	// 정렬
	sort(arr, arr + n, compare);

	// 첫번째는 push, 두번째 부터는 end와 start가 연결이 가능하면 push
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			s.push(make_pair(arr[i].start, arr[i].end));
		}
		else {
			if (arr[i].start >= s.top().second) {
				s.push(make_pair(arr[i].start, arr[i].end));
			}
		}
	}

	// 출력
	cout << s.size();

	return 0;
}