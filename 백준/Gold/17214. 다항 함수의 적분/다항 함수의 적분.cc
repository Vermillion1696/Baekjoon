#include <iostream>
#include <cmath>
using namespace std;
#define empty 10001

// 숫자인지 반환하는 함수
bool isNumber(const char& c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

// 숫자 저장 함수
void save(const int& total, int& linear, int& constant, const bool& negative, const bool& locateLINEAR) {
	if (!locateLINEAR) {
		!negative ? constant = total : constant = -total;
	}
	else {
		!negative ? linear = total : linear = -total;
	}
	return;
}

void integrate(int& linear, int& constant, const string& str) {
	long long total = 0; int cnt = 0;
	const int length = str.length();
	bool put = false, negative = false, locateLINEAR = false;

	for (int i = length - 1; i >= 0; i--) {
		// 숫자를 만나면 입력을 켠다
		isNumber(str[i]) ? put = true : put = false;
		
		// x를 만나면 1차항 계수 자리 입력을 켠다
		if (str[i] == 'x') {
			locateLINEAR = true;
		}

		// 입력이 켜진 상태면 입력을 받는다
		if (put) {
			total += (str[i] - '0') * pow(10, cnt);
			cnt++;
		}
		
		// 입력 정지 상황
		if (str[i] == '+' || str[i] == '-' || i == 0) {
			// 마지막인데 숫자가 아닌 경우 -> -3x, x, x+41...
			if (i == 0 && !put) {
				// x+c인 경우
				if (str[i] != '-') {
					total = 1;
					negative = false;
				}
				// -ax+c인 경우
				else {
					negative = true;
				}

				save(total, linear, constant, negative, locateLINEAR);
			}
			else {
				// + 또는 숫자면 음수가 아님
				(str[i] == '+' || isNumber(str[i])) ? negative = false : negative = true;
				save(total, linear, constant, negative, locateLINEAR);
			}

			// 입력 초기화
			cnt = 0;
			total = 0;
			negative = false;

			// 둘 다 입력 했으면 종료
			if (constant != empty && linear != empty) {
				return;
			}
		}
	}

	return;
}

int main() {
	string str;
	cin >> str;

	// 문자열 길이, 10^(cnt)
	int length = str.length(), cnt = 0;
	int linear = empty, constant = empty;
	integrate(linear, constant, str);
	bool plusOUT = false;

	//cout << linear << " " << constant << "\n";

	// linear가 입력이 안 되어있거나 0이면 출력 X
	if (linear != empty && linear != 0) {
		// 2면 출력이 1이므로 의도적으로 비움
		if (linear == 2) {
		}
		// -2면 출력이 -1이므로 - 출력 (1생략)
		else if (linear == -2) {
			cout << "-";
		}
		// 아니면 숫자 출력
		else {
			cout << linear / 2;
		}
		cout << "xx";
		plusOUT = true;
	}

	// constant가 입력이 안 되어있거나 0이면 출력 X
	if (constant != empty && constant != 0) {
		// 양수인데 앞 항이 있다면 + 출력
		if (constant > 0 && linear != empty) {
			cout << "+";
		}
		
		// 1이면 출력이 1이므로 의도적으로 비움
		if (constant == 1) {
		}
		// -1이면 출력이 -1이므로 - 출력 (1생략)
		else if (constant == -1) {
			cout << "-";
		}
		// 아니면 숫자 출력
		else {
			cout << constant;
		}
		cout << "x";
		plusOUT = true;
	}

	// 상수항 앞에 +를 내보내야 하면 출력
	if (plusOUT) {
		cout << "+";
	}
	cout << "W";

	return 0;
}