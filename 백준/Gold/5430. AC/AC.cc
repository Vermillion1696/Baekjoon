#include <iostream>
#include <cmath>
#include <deque>
#include <string>
using namespace std;

// 파싱, 문자열로 주어지는 입력을 정수 덱으로 전환
void parshing(deque<int>& dq, string matrix) {
	int num = 0;
	int cnt = 0;

	for (int i = matrix.length() - 2; i >= 0; i--) {

		// 정지포인트 , [
		if (matrix[i] == ',' || matrix[i] == '[') {
			if (num == 0) {
				return;
			}
			dq.push_front(num);
			num = 0;
			cnt = 0;
		}
		// 아니면 10의 지수 올림
		else {
			num += pow(10, cnt) * (matrix[i] - '0');
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// 테스트 케이스
	int tc;
	cin >> tc;

	while (tc--) {
		// reverse, error 판별 bool, deque, 개수 count, 명령어, 숫자 string
		bool reverse = 0;
		bool error = 0;
		deque<int> dq;
		int count;
		string command, matrix;
		
		// 입력
		cin >> command;
		cin >> count;
		cin >> matrix;

		// 파싱
		parshing(dq, matrix);
		
		// command string analysis
		for (int i = 0; command[i] != NULL; i++) {
			// R인 경우 reverse bool에 NOT 씌우기
			if (command[i] == 'R') {
				reverse = !reverse;
			}
			// D인 경우
			else {
				// dq가 비었으면 error = true 하고 break;
				if (dq.empty()) {
					error = 1;
					break;
				}
				// 아니면 reverse 여부에 따라 넣는 위치 결정
				else {
					reverse ? dq.pop_back() : dq.pop_front();
				}
			}
		}

		// 에러면 에러 메시지 출력
		if (error) {
			cout << "error\n";
		}
		// 에러가 아니면 iterator를 이용한 출력
		else {
			deque<int> ::iterator iter;

			cout << '[';
			// reverse 이면서 출력할 게 남은 경우 -> rbegin, rend
			if (reverse && !dq.empty()) {
				for (auto i = dq.rbegin(); i != dq.rend(); i++) {
					i != dq.rend() - 1 ? cout << *i << ',' : cout << *i;
				}
			}
			// !reverse 이면서 출력할 게 남은 경우 -> begin, end
			else if (!reverse && !dq.empty()) {
				for (auto i = dq.begin(); i != dq.end(); i++) {
					i != dq.end() - 1 ? cout << *i << ',' : cout << *i;
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}