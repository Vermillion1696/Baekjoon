#include <iostream>
#define MAX 501
using namespace std;
int row, col;
int map[MAX][MAX];

int four_finder() {
	int cur_sum, max_sum = 0;

	// 4x1 인 4칸중 최대 합 찾기
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col - 3; j++) {

			cur_sum = 0;
			for (int dx = 0; dx < 4; dx++) {
				cur_sum += map[i][j + dx];
			}

			max_sum = max(cur_sum, max_sum);
		}
	}

	// 1x4 인 4칸중 최대 합 찾기
	for (int i = 1; i <= row - 3; i++) {
		for (int j = 1; j <= col; j++) {

			cur_sum = 0;
			for (int dy = 0; dy < 4; dy++) {
				cur_sum += map[i + dy][j];
			}

			max_sum = max(cur_sum, max_sum);
		}
	}

	// 3x2에서 S, Z, T, L중 최대 합 찾기
	for (int i = 1; i <= row - 1; i++) {
		for (int j = 1; j <= col - 2; j++) {

			cur_sum = 0;

			// T, L
			int three_first = map[i][j] + map[i][j + 1] + map[i][j + 2];
			int three_second = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];

			// i열 3개에 i + 1열에서 1개를 뽑음
			// i + 1열 3개에 i열에서 1개를 뽑음
			for (int dx = 0; dx < 3; dx++) {
				cur_sum = max(three_first + map[i + 1][j + dx], cur_sum);
				cur_sum = max(three_second + map[i][j + dx], cur_sum);
			}

			// S, Z
			int S = 0, Z = 0;
			for (int dx = 0; dx < 2; dx++) {
				S += map[i][j + dx];
				S += map[i + 1][j + 1 + dx];

				Z += map[i][j + 1 + dx];
				Z += map[i + 1][j + dx];
			}

			cur_sum = max(cur_sum, S);
			cur_sum = max(cur_sum, Z);

			max_sum = max(cur_sum, max_sum);
		}
	}

	// 2x3에서 S, Z, T, L중 최대 합 찾기
	for (int i = 1; i <= row - 2; i++) {
		for (int j = 1; j <= col - 1; j++) {

			cur_sum = 0;

			// T, L
			int three_first = map[i][j] + map[i + 1][j] + map[i + 2][j];
			int three_second = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];

			// j행 3개에 j + 1행에서 1개를 뽑음
			// j + 1행 3개에 j행에서 1개를 뽑음
			for (int dy = 0; dy < 3; dy++) {
				cur_sum = max(three_first + map[i + dy][j + 1], cur_sum);
				cur_sum = max(three_second + map[i + dy][j], cur_sum);
			}

			// S, Z
			int S = 0, Z = 0;
			for (int dy = 0; dy < 2; dy++) {
				S += map[i + dy][j];
				S += map[i + 1 + dy][j + 1];

				Z += map[i + 1 + dy][j];
				Z += map[i + dy][j + 1];
			}

			cur_sum = max(cur_sum, S);
			cur_sum = max(cur_sum, Z);

			max_sum = max(cur_sum, max_sum);
		}
	}

	// 2x2에서 최대 합 찾기
	for (int i = 1; i <= row - 1; i++) {
		for (int j = 1; j <= col - 1; j++) {
			cur_sum = 0;

			cur_sum = max(cur_sum, map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1]);
		
			max_sum = max(cur_sum, max_sum);
		}
	}

	return max_sum;
}

int main() {
	cin >> row >> col;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}

	cout << four_finder();

	return 0;
}