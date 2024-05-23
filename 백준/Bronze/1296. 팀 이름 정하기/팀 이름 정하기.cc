#include <iostream>
#include <vector>
using namespace std;
vector<pair<string, int>> v;

// 점수 계산 함수
int percentage(int L, int O, int V, int E) {
	return ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
}

// 최종 점수 함수
int love(int L, int O, int V, int E, const string& name) {

	for (int i = 0; name[i] != NULL; i++) {
		if (name[i] == 'L') {
			L++;
		}
		else if (name[i] == 'O') {
			O++;
		}
		else if (name[i] == 'V') {
			V++;
		}
		else if (name[i] == 'E') {
			E++;
		}
	}
	
	return percentage(L, O, V, E);
}

int main() {

	// 입력
	string name;
	int n;
	cin >> name >> n;

	// 연두의 이름 속 LOVE
	int LOVE[4] = { 0, };
	for (int i = 0; name[i] != NULL; i++) {
		if (name[i] == 'L') {
			LOVE[0]++;
		}
		else if (name[i] == 'O') {
			LOVE[1]++;
		}
		else if (name[i] == 'V') {
			LOVE[2]++;
		}
		else if (name[i] == 'E') {
			LOVE[3]++;
		}
	}

	// vector pair로 이름, 확률 보관
	while (n--) {
		cin >> name;
		v.push_back(make_pair(name, love(LOVE[0], LOVE[1], LOVE[2], LOVE[3], name)));
	}

	// 최댓값, 최댓값의 인덱스 찾기
	int max = -1;
	int maxIndex = 0;
	for (int i = 0; i < v.size(); i++) {
		if (max < v[i].second) {
			max = v[i].second;
			maxIndex = i;
		}
		// 값이 같을 땐 사전순으로
		else if (max == v[i].second) {
			if (v[i].first < v[maxIndex].first) {
				maxIndex = i;
			}
		}
	}

	// 출력
	cout << v[maxIndex].first;
	
	return 0;
}