#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// number의 모든 자리 수가 사용 가능하면 true 반환, 특이 케이스 number == 0일 때만 예외 처리
bool scan(int number, vector<bool>& v) {
	if (number == 0) {
		if (v[0] == 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		while (number > 0) {
			if (v[number % 10] == 1) {
				return 0;
			}
			number /= 10;
		}
	}
	return 1;
}

// number는 n자리 수, n 반환, 특이 케이스 number == 0 일때만 1 반환
int sizeofNum(int number) {
	int cnt = 0;
	if (number == 0) {
		return 1;
	}
	else {
		while (number > 0) {
			number /= 10;
			cnt++;
		}
	}
	return cnt;
}

// 만들 수 있는 수중 target보다 작거나 같은 수 부터 target까지 걸리는 클릭 횟수
int targetLowerBound(int target, vector<bool>& v) {
	
	// initial : 초기 target
	int initial = target;

	// 모든 자리 수가 사용 가능한 수 일 때까지
	while (!scan(target, v)) {
		target--;

		// 0도 안 되면 불가능 판정
		if (target < 0) {
			return 999999;
		}
	}

	return (initial - target + sizeofNum(target));
}

// 만들 수 있는 수중 target보다 크거나 같은 수 부터 target까지 걸리는 클릭 횟수
int targetUpperBound(int target, vector<bool>& v) {

	// initial : 초기 target
	int initial = target;

	// 모든 자리 수가 사용 가능한 수 일 때까지
	while (!scan(target, v)) {
		target++;

		// 최대 숫자 자리 수를 넘어가면 break
		if (target > 999999) {
			return 999999;
		}
	}

	return (target - initial + sizeofNum(target));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 목표, 부서진 버튼 개수, 부서진 숫자 담을 변수
	int target, buttonBroken, brokenNum;
	cin >> target >> buttonBroken;

	// false면 not broken
	vector<bool> v = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// 사용 불가능한 버튼은 1로 바꿈
	// 0 번이 고장났다 ? v[0] == 1
	while (buttonBroken--) {
		cin >> brokenNum;
		v[brokenNum] = 1;
	}

	bool bound[2];

	// 100부터 출발 vs LowerBound부터 출발 vs UpperBound부터 출발
	// 모든 버튼이 부러졌으면 100부터 출발하는 케이스 밖에 없다
	if (buttonBroken == 10) {
		cout << abs(100 - target);
	}
	else {
		int minimum = min(targetLowerBound(target, v), targetUpperBound(target, v));
		minimum = min(minimum, abs(100 - target));
		cout << minimum;
	}

	// 디버깅용 코드
	/*
	cout << "\n\n";
	
	int minimum = min(targetLowerBound(target, v), targetUpperBound(target, v));
	minimum = min(minimum, abs(100 - target));

	cout << "100부터 : " << abs(100 - target) << "\n";
	cout << "LowerBound 부터 : " << targetLowerBound(target, v) << "\n";
	cout << "UpperBound 부터 : " << targetUpperBound(target, v);
	*/

	return 0;
}