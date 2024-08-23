// 사전지식 : 피보나치의 행렬곱표현
// 1 1 
// 1 0
// 행렬 A 를 n-1승하면 A11 == Fn, A21 == Fn-1이다. (Aij에서 i는 행, j는 열)

#include <iostream>
using namespace std;
using ll = long long;
constexpr int mod = 1000000007;
ll matrix[2][2] = { {1,1}, {1,0} };

// fibo_matrix와 multiply_matrix의 행렬곱을 fibo_matrix에 저장
void matrix_multiply(ll fibo_matrix[2][2], ll multiply_matrix[2][2]) {
	ll a = fibo_matrix[0][0] * multiply_matrix[0][0] + fibo_matrix[0][1] * multiply_matrix[1][0];
	ll b = fibo_matrix[0][0] * multiply_matrix[0][1] + fibo_matrix[0][1] * multiply_matrix[1][1];
	ll c = fibo_matrix[1][0] * multiply_matrix[0][0] + fibo_matrix[1][1] * multiply_matrix[1][0];
	ll d = fibo_matrix[1][0] * multiply_matrix[0][1] + fibo_matrix[1][1] * multiply_matrix[1][1];

	fibo_matrix[0][0] = a % mod;
	fibo_matrix[0][1] = b % mod;
	fibo_matrix[1][0] = c % mod;
	fibo_matrix[1][1] = d % mod;

	return;
}

void power(ll fibo_matrix[2][2], ll n) {
	if (n == 0 || n == 1) return;

	ll multiply_matrix[2][2] = { {1,1}, {1,0} };

	// fibo_matrix를 fibo_matrix의 n/2승으로 바꿈
	power(fibo_matrix, n / 2);
	
	// fibo_matrix를 fibo_matrix의 2승으로 바꿈
	// 즉, fibo_matrix의 n승과 같음 (n이 짝수인 경우)
	matrix_multiply(fibo_matrix, fibo_matrix);

	// n이 홀수인 경우 +1승을 해줘야 함
	if (n % 2 == 1) matrix_multiply(fibo_matrix, multiply_matrix);

	return;
}

int main() {
	ll n;
	cin >> n;

	ll main_matrix[2][2] = { {1,1}, {1,0} };
	power(main_matrix, n - 1);

	cout << main_matrix[0][0];
}