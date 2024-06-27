#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;

	// 문자열 길이, 10^(cnt)
	int length = str.length(), cnt = 0;
	long long int total = 0;
	bool derivative = false, negative = false, just1 = true;

	// 문자열을 끝부터 처음으로 탐색
	for (int i = length - 1; i >= 0; i--) {
		// x면 다음 글자부터 입력 받기 시작
		if (str[i] == 'x') {
			derivative = true;
			just1 = true;
		}
		// -가 아니면 (현재 숫자) * 10^(cnt)를 더함
		// ex. 453 -> 4 * 10^2 + 5 * 10^1 + 3 * 10^0
		else if (derivative && str[i] != '-') {
			just1 = false;
			total += (str[i] - '0') * pow(10, cnt);
			cnt++;
		}
		// -면 음수라는 표시를 남기고 break
		else if (derivative && str[i] == '-') {
			negative = true;
			break;
		}
	}

	// 식이 상수인 경우
	if (!derivative) {
		cout << 0;
	}
	// 1인 경우, 음수 판별
	else if (just1) {
		negative ? cout << -1 : cout << 1;
	}
	// 음수인 경우
	else if (negative) {
		cout << "-" << total;
	}
	// 양수인 경우
	else {
		cout << total;
	}

	return 0;
}