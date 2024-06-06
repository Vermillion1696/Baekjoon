#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	// 단어 길이, 부분 연속 개수, 최대 연속 개수
	int length, cnt, max;
	char chr;
	while (tc--) {
		cin >> length;

		max = 0;
		cnt = 0;
		while (length--) {
			cin >> chr;

			// X면 부분 연속 +1
			if (chr == 'X') {
				cnt++;
			}
			// O면 최고 부분 연속일 때를 max에 대입
			else if (chr == 'O') {
				if (cnt >= max) {
					max = cnt;
				}
                cnt = 0;
			}

		}

		// 끝이 O로 끝나지 않아 마지막 케이스 비교가 안 된 경우
		if (cnt >= max) {
			max = cnt;
		}

		// 출력
		cout << "The longest contiguous subsequence of X's is of length " << max << "\n";
	}

	return 0;
}