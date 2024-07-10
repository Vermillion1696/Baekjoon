#include <iostream>
#define MAX 450
using namespace std;
bool board[MAX][MAX];

// star == true -> '*', star == false -> ' '
void square(int size, int adjust, bool star) {

	// 테두리 칠하기
	int min = 1 + adjust, max = size - adjust;
	for (int i = min; i <= max; i++) {
		board[i][min] = star;
		board[i][max] = star;
		board[min][i] = star;
		board[max][i] = star;
	}

	// 크기가 항상 4n + 1이므로 한 점에서 만남이 보장된다
	// 한 점에서 만나지 않으면 조정값을 추가하고 !star를 넣음
	if (min != max) square(size, adjust + 1, !star);

	return;
}

int main() {
	int n;
	cin >> n;

	int size = ((n - 1) * 4 + 1);
	bool star = true;
	square(size, 0, star);

	// 1이면 별 0이면 빈칸
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			board[i][j] == 1 ? cout << '*' : cout << ' ';
		}
		cout << "\n";
	}

	return 0;
}