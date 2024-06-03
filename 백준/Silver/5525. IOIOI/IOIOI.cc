#include <iostream>
#include <vector>
using namespace std;

// 등장한 IO...I 들의 n을 벡터에 넣는 함수
void ioCounter(string& str, vector<int>& v, int& length) {
	int io = 0;
	bool countStart = 0;
	for (int i = 0; i < length - 1; i++) {

		// I를 만났는데 카운팅 상태가 아니면 카운팅으로 전환
		if (str[i] == 'I' && !countStart) {
			countStart = 1;
		}

		// I를 만났는데 카운팅 상태면
		if (str[i] == 'I' && countStart) {

			// 다음 문자가 O면 io++;
			if (str[i + 1] == 'O') {
				io++;
			}
			// 다음 문자가 I면 벡터에 넣고 io = 0;
			else {
				countStart = 0;
				v.push_back(io);
				io = 0;
			}
		}

		// O를 만났는데 카운팅 상태면
		if (str[i] == 'O' && countStart) {

			// 다음 문자가 O면 io--, 벡터에 넣고 io = 0;
			if (str[i + 1] == 'O') {
				countStart = 0;
				io--;
				v.push_back(io);
				io = 0;
			}
		}
	}

	// length - 2번까지 검사 했으므로 끝 자리 검사 후 처리
	// io 값이 아직 안 들어갔고 끝이 I면 push
	if (io != 0 && str[length - 1] == 'I') {
		v.push_back(io);
	}
	// io 값이 아직 안 들어갔고 끝이 O면 1 빼고 push
	// ex. IOIOIOIO : Pn은 max 3이지만 위 알고리즘상으로는 4이므로.
	else if (io != 0 && str[length - 1] == 'O') {
		io--;
		v.push_back(io);
	}
}

int main() {
	int n, length;
	cin >> n >> length;

	string str;
	cin >> str;

	vector<int> v;

	ioCounter(str, v, length);

	// 디버깅 코드
	/*
	while (!v.empty()) {
		cout << v.back() << "\n";
		v.pop_back();
	}
	*/

	// Pn의 등장 횟수 : 벡터 원소 - n + 1
	int total = 0;
	while (!v.empty()) {
		// IO 등장 횟수가 v.back()이 n보다 크거나 같을 때만 추가
		if (v.back() >= n) {
			total += v.back() - n + 1;
			v.pop_back();
		}
		else {
			v.pop_back();
		}
	}

	cout << total;

	return 0;
}