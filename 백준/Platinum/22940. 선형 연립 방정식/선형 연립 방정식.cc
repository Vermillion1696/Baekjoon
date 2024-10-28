// 20307 - RREF 문제 제출 코드 약간 수정
// http://boj.kr/9534715826034a14af60ba53c725546e

#include <iostream>
#include <vector>
#include <string>
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;

// 최대공약수
ll GCD(ll left, ll right) {
    while (right != 0) {
        ll div = left % right;
        left = right;
        right = div;
    }
    return left;
}

// 절댓값 취하기
ll ABS(ll orig) {
    if (orig < 0) orig *= -1;
    return orig;
}

class fraction {
public:
    fraction() {};
    fraction(ll a, ll b) {
        upper = a;
        lower = b;
    }

    bool operator==(const fraction& other) const {
        return (this->upper == other.upper) && (this->lower == other.lower);
    }

    bool operator!=(const fraction& other) const {
        return !(*this == other);
    }

    // a/b + c/d = (ad + bc) / bd
    fraction operator+(const fraction& other) const {
        fraction result;
        result.lower = this->lower * other.lower;
        result.upper = (this->lower * other.upper) + (this->upper * other.lower);

        ll cur_gcd = GCD(ABS(result.lower), ABS(result.upper));
        result.lower /= cur_gcd;
        result.upper /= cur_gcd;

        if (result.lower < 0) {
            result.lower *= -1;
            result.upper *= -1;
        }

        return result;
    }

    // a/b * c/d = ac/bd
    fraction operator*(const fraction& other) const {
        fraction result;
        result.lower = this->lower * other.lower;
        result.upper = this->upper * other.upper;

        ll cur_gcd = GCD(ABS(result.lower), ABS(result.upper));
        result.lower /= cur_gcd;
        result.upper /= cur_gcd;

        if (result.lower < 0) {
            result.lower *= -1;
            result.upper *= -1;
        }

        return result;
    }

    fraction operator/(const fraction& other) const {
        fraction reversed(other.lower, other.upper);
        return (*this) * reversed;
    }

    fraction& operator=(const fraction& other) {
        if (this == &other) return *this;

        this->lower = other.lower;
        this->upper = other.upper;
        return *this;
    }

    // ostream 출력 연산자 << 재정의 (분수 한 번에 출력하게)
    friend ostream& operator<<(ostream& out, const fraction& output) {
        out << output.upper << '/' << output.lower;
        return out;
    }

    ll upper = -1;
    ll lower = -1;
    ~fraction() {};
};

int row, col;
fraction RREF[50][50];
fraction zero(0, 1);

// second_col += first_col * mult_f;
void Replacement(int pivot_row_num, int target_row_num, const fraction& mult_f) {
    for (int i = 1; i <= col; i++) {
        RREF[target_row_num][i] = RREF[pivot_row_num][i] * mult_f + RREF[target_row_num][i];
    }
    return;
}
void Scale(int row_num, const fraction& mult_f) {
    for (int i = 1; i <= col; i++) {
        RREF[row_num][i] = RREF[row_num][i] * mult_f;
    }
    return;
}
void Swap(int row_num1, int row_num2) {
    for (int i = 1; i <= col; i++) {
        swap(RREF[row_num1][i], RREF[row_num2][i]);
    }
    return;
}

// 리턴값이 원본 분수의 부호 반전
fraction reverseSign(const fraction& original) {
    fraction result(-original.upper, original.lower);
    return result;
}
// 리턴값이 원본 분수의 역수
fraction reciprocalPos(const fraction& original) {
    fraction result(original.lower, original.upper);
    return result;
}
// 리턴값이 원본 분수의 부호 반전 + 역수
fraction reciprocalNeg(const fraction& original) {
    fraction result(-original.lower, original.upper);
    return result;
}

// 디버깅용 RREF 출력 함수
void printRREF() {
    cout << '\n';
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << RREF[i][j].upper << '/' << RREF[i][j].lower << ' ';
        }
        cout << '\n';
    }
    return;
}

int main() {
    fast_io;

    cin >> row;
    col = row + 1;

    // 입력
    string input_str;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> input_str;

            // 분수가 아닌 경우
            if (input_str.find('/') == string::npos) {
                RREF[i][j].upper = stoi(input_str);
                RREF[i][j].lower = 1;
            }
            // 분수인경우
            else {
                int fraction_index = input_str.find('/');
                RREF[i][j].upper = stoi(input_str.substr(0, fraction_index));
                RREF[i][j].lower = stoi(input_str.substr(fraction_index + 1));
            }
        }
    }

    int pivot_row = 0;

    for (int cur_col = 1; cur_col <= col; cur_col++) {

        int pivot_index = -1;

        // 현재 열에서 pivot 찾기
        // pivot_row 다음 열부터 찾아야 한다
        for (int row_i = pivot_row + 1; row_i <= row; row_i++) {
            if (RREF[row_i][cur_col] != zero) { // pivot을 찾음
                pivot_index = row_i;
                break;
            }
        }

        if (pivot_index != -1) {
            pivot_row++;

            // pivot 행 내림차순
            if (pivot_index != pivot_row) {
                Swap(pivot_index, pivot_row);
            }

            // pivot 행 1로 scaling
            Scale(pivot_row, reciprocalPos(RREF[pivot_row][cur_col]));

            // pivot 열에서 pivot이 아닌 원소 제거
            for (int row_i = 1; row_i <= row; row_i++) {
                if (row_i != pivot_row) {
                    Replacement(pivot_row, row_i, reverseSign(RREF[row_i][cur_col]));
                }
            }
        }
    }

    // 자연수임을 보장하므로 upper만 (분자) 출력
    for (int i = 1; i <= row; i++) {
        cout << RREF[i][col].upper << ' ';
    }

    return 0;
}