#include <iostream>
#include <vector>
using namespace std;

// 3개 이상 겹치는 mbti가 있으면 심리적 거리의 최소는 항상 0
bool same3Counter(vector<string> v) {
	string top = v.back();
	int cnt = 0;
	while (!v.empty()) {
		if (top.compare(v.back()) == 0) {
			cnt++;
			if (cnt >= 3) {
				return 1;
			}
		}
		v.pop_back();
	}
	return 0;
}

// 두 사람 간 심리적 거리 계산 함수
int different(string s1, string s2) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] != s2[i]) {
			cnt++;
		}
	}
	return cnt;
}

// 세 사람 간 심리적 거리 계산 함수
int distance(string s1, string s2, string s3) {
	int cnt = different(s1, s2) + different(s2, s3) + different(s3, s1);
	return cnt;
}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		vector<string> v;
		int people;
		string mbti;
		bool three = 0;

		// 입력 받은 사람 명 수 만큼
		cin >> people;
		for (int i = 0; i < people; i++) {
			cin >> mbti;

			// 세 명이 넘어가면 입력을 안 받음
			if (!three) {
				v.push_back(mbti);

				// push로 세 명이 넘어가게 되면 three = 1;
				if (v.size() >= 3 && same3Counter(v)) {
					three = 1;
				}
			}
		}

		// 마지막 인덱스, 최소 세 사람간 심리적 거리는 최댓값인 12보다 큰 수 20으로 잡음
		int lastIndex = v.size() - 1;
		int minimum = 20;

		// 3중 for문으로 브루트포스
		for (int i = 0; i <= lastIndex - 2; i++) {
			for (int j = i + 1; j <= lastIndex - 1; j++) {
				for (int k = j + 1; k <= lastIndex; k++) {
					if (distance(v[i], v[j], v[k]) < minimum) {
						minimum = distance(v[i], v[j], v[k]);
					}
				}
			}
		}

		// 출력
		three ? cout << "0\n" : cout << minimum << "\n";
	}

	return 0;
}