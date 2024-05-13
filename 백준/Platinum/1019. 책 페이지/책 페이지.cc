#include <iostream>
using namespace std;
// 발상 참고 : https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019

// 각 숫자가 얼마나 나왔는지
long long arr[10] = { 0, };

// 값을 조정할 때 각 자리 수를 더하는 함수
// n -> 입력수, pow -> 자리 보정값
void calc(long long int n, long long int pow)
{
	while (n > 0) {
		arr[n % 10] += pow;
		n /= 10;
	}
}

// 실제 함수
void func(long long int a, long long int b, long long int pow) {

	// A 끝자리를 0으로 조정
	while (a % 10 != 0 && a <= b)
	{
		calc(a, pow);
		a++;
	}

	// A가 B보다 커지면 함수 종료
	if (a > b) {
	return;
	}

	// B 끝자리를 9로 조정
	while (b % 10 != 9 && b >= a)
	{
		calc(b, pow);
		b--;
	}

	// A가 B보다 커지면 함수 종료
	if (a > b) {
		return;
	}

	// NNN0 ~ MMM9는 (MMM - NNN + 1) * 조정값 pow 만큼 있다
	long long int temp = (b / 10 - a / 10 + 1);
	for (int i = 0; i < 10; ++i) {
		arr[i] += temp * pow;
	}

	// 다음 리턴을 위한 재귀적 호출
	func(a / 10, b / 10, pow * 10);
}

int main() {
    
	// n -> 입력
	long long int n;
	cin >> n;

	// 재귀 함수 호출
	func(1, n, 1);

	// 결과 출력
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}