#include <iostream>
#include <set>
using namespace std;

constexpr int A = 1;
constexpr int B = 2;
constexpr int C = 3;
constexpr int D = 4;
constexpr int E = 5;
int dp[100000][6];

int main() {
	int N;
	cin >> N;

	int mingrd = 5, maxpep = 1;
	int val1, val2;
	int b41, b42;

	cin >> val1 >> val2;

	// 초기 세팅
	dp[0][val1]++;
	if(val1 != val2) dp[0][val2]++;
	b41 = val1;
	b42 = val2;
	mingrd = min(val1, val2);

	for (int desk = 1; desk < N; desk++) {

		cin >> val1 >> val2;

		for (int grade = A; grade <= E; grade++) {
			// 입력인 경우
			if (grade == val1 || grade == val2) {
				
				// 이전 최대치 + 1
				dp[desk][grade] = dp[desk - 1][grade] + 1;

				// 최대 갱신
				if (dp[desk][grade] > maxpep) {
					maxpep = dp[desk][grade];
					mingrd = grade;
				}
				// 최대가 같을 때 grade 세팅
				else if (dp[desk][grade] == maxpep) {
					mingrd = min(mingrd, grade);
				}
			}
			// 입력이 아닌 경우
			else {
				dp[desk][grade] = 0;
			}
		}
	}

	cout << maxpep << ' ' << mingrd;

	return 0;
}