#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000;

// 피보나치 수열의 행렬 표현
// [1, 1] 을 n-1승 하면 1행1열이 F(n)이고, 2행1열이 F(n-1)이다
// [1, 0]

ll original_matrix[2][2] = { {1,1}, {1,0} };
ll main_matrix[2][2] = { {1,1}, {1,0} };

// 행렬 곱셈 함수
void multiply_matrix(ll target_matrix[2][2], ll multi_matrix[2][2]) {
	ll return_matrix[2][2] = {};

	// 행렬 곱셈
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				return_matrix[i][j] += target_matrix[i][k] * multi_matrix[k][j];
				return_matrix[i][j] %= mod;
			}
		}
	}

	// 저장 배열에 들어있던 값을 원 배열에 이식
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			target_matrix[i][j] = return_matrix[i][j];
		}
	}

	return;
}

// 행렬 n승 함수
void power_matrix(ll target_matrix[2][2], ll pow) {
	
	// 0승인경우 단위행렬
	if (pow == 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				target_matrix[i][j] = (i == j) ? 1 : 0;
			}
		}
		return;
	}
	// 1승인경우 자기 자신
	else if (pow == 1) {
		return;
	}

	// 분할정복을 이용한 거듭제곱
	power_matrix(target_matrix, pow / 2);
	multiply_matrix(target_matrix, target_matrix);

	// 홀수 승일 경우 원래 행렬 한 번 더 곱해줌
	if (pow % 2 != 0) multiply_matrix(target_matrix, original_matrix);

	return;
}

int main() {
	ll n;
	cin >> n;

	// {{1,1}, {1,0}}^(n-1) 후 matrix[0][0]은 F(n), matrix[1][0]은 F(n-1)
	power_matrix(main_matrix, n - 1);

	cout << main_matrix[0][0];

	return 0;
}
