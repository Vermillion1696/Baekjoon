#include <iostream>
using namespace std;
using ll = long long;
int matrix_size;
ll original_matrix[5][5];
ll matrix[5][5];

// 단위 행렬로 바꾸는 함수
void identity_matrix(ll main_matrix[5][5]) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			i == j ? main_matrix[i][j] = 1 : main_matrix[i][j] = 0;
		}
	}
	return;
}

// 두 행렬을 곱하는 함수
void multiply_matrix(ll main_matrix[5][5], ll multiply_matrix[5][5]) {
	
	// 곱한 결과를 저장할 행렬
	ll return_matrix[5][5] = {};
	
	// 행렬의 모든 원소를 돌 때까지
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			
			return_matrix[i][j] = 0;

			// ex. c(11) = a(11)b(11) + a(12)b(21) + a(13)b(31)
			for (int k = 0; k < matrix_size; k++) {
				return_matrix[i][j] += main_matrix[i][k] * multiply_matrix[k][j];
			}

			return_matrix[i][j] %= 1000;
		}
	}

	// 결과를 main_matrix에 저장
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			main_matrix[i][j] = return_matrix[i][j];
		}
	}

	return;
}

// 행렬을 제곱 하는 함수
void power_matrix(ll main_matrix[5][5], ll times) {

	if (times == 0) {
		identity_matrix(main_matrix);
		return;
	}
	if (times == 1) return;

	power_matrix(main_matrix, times / 2); // (main_matrix)^(1/2)
	multiply_matrix(main_matrix, main_matrix); // (main_matrix)^(1)

	if (times % 2 != 0) multiply_matrix(main_matrix, original_matrix);

	return;
}

int main() {
	ll times;
	cin >> matrix_size >> times;

	// 입력
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cin >> matrix[i][j];
			original_matrix[i][j] = matrix[i][j];
		}
	}

	power_matrix(matrix, times);

	// 출력
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << matrix[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}