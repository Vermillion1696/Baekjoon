#include <iostream>
using namespace std;
// point :
// 사용자 지정 함수 선언 후 내부 포인터로 직접 카운팅 해 보면
// 0, 1 역시 피보나치 숫자로 증가함을 확인할 수 있다
// 단, 그 상태로 돌리면 TLE가 나기 때문에... ex. 40

int main() {
	
	// 피보나치 수열을 미리 입력 받는다
	// 크기가 41인 이유는 n = 40인 경우일 때 40번째 수, 41번째 수 출력
	int fibonacci[41];
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i < 41; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	// 테스트 케이스
	int testCase;
	cin >> testCase;

	// n에 따른 출력 결과
	int n;
	for (int i = 0; i < testCase; i++) {
		cin >> n;

		if (n == 0) {
			cout << "1 0" << endl;
		}
		else if (n == 1) {
			cout << "0 1" << endl;
		}
		else {
			cout << fibonacci[n - 1] << " " << fibonacci[n] << endl;
		}
	}

	return 0;
}