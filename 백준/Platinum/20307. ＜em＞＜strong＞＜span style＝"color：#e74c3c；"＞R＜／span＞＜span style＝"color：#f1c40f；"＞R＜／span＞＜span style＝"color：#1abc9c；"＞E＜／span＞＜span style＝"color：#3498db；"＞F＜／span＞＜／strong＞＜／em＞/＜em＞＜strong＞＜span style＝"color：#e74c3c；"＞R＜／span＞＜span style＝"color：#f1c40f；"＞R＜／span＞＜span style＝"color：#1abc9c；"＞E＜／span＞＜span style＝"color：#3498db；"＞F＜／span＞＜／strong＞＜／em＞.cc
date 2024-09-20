// <bits/stdc++.h> 내장 헤더 전부 include
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// BIG INT
// reference : https://codeforces.com/blog/entry/16380
/*
  ######################################################################
  #######################   THE   BIG   INT   ##########################
*/
const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a;
    int sign;
    /*<arpa>*/
    int size() {
        if (a.empty())return 0;
        int ans = (a.size() - 1) * base_digits;
        int ca = a.back();
        while (ca)
            ans++, ca /= 10;
        return ans;
    }
    bigint operator ^(const bigint& v) {
        bigint ans = 1, a = *this, b = v;
        while (!b.isZero()) {
            if (b % 2)
                ans *= a;
            a *= a, b /= 2;
        }
        return ans;
    }
    string to_string() {
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof() {
        string s = to_string();
        int ans = 0;
        for (auto c : s)  ans += c - '0';
        return ans;
    }
    /*</arpa>*/
    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string& s) {
        read(s);
    }

    void operator=(const bigint& v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint& v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int)res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint& v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    void operator*=(long long v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(long long v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint& a1, const bigint& b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long)base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint& v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint& v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long)base;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long)base) % v;
        return m * sign;
    }

    void operator+=(const bigint& v) {
        *this = *this + v;
    }
    void operator-=(const bigint& v) {
        *this = *this - v;
    }
    void operator*=(const bigint& v) {
        *this = *this * v;
    }
    void operator/=(const bigint& v) {
        *this = *this / v;
    }

    bool operator<(const bigint& v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint& v) const {
        return v < *this;
    }
    bool operator<=(const bigint& v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint& v) const {
        return !(*this < v);
    }
    bool operator==(const bigint& v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint& v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint& a, const bigint& b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint& a, const bigint& b) {
        return a / gcd(a, b) * b;
    }

    void read(const string& s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream& stream, bigint& v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream& stream, const bigint& v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll& a, const vll& b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int)r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint& v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
/*
  #######################   THE   BIG   INT   ##########################
  ######################################################################
*/

// 최대공약수
bigint GCD(bigint left, bigint right) {
	while (right != 0) {
		bigint div = left % right;
		left = right;
		right = div;
	}
	return left;
}

// 절댓값 취하기
bigint ABS(bigint orig) {
    if (orig < 0) orig *= -1;
    return orig;
}

class fraction {
public:
	fraction() {};
	fraction(bigint a, bigint b) {
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
		
		bigint cur_gcd = GCD(ABS(result.lower), ABS(result.upper));
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

		bigint cur_gcd = GCD(ABS(result.lower), ABS(result.upper));
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

	bigint upper = -1;
	bigint lower = -1;
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
// RREF 출력 함수
void printRREF(bool frac_mode) {
	if (!frac_mode) {
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cout << RREF[i][j].upper;
				if (RREF[i][j].lower != 1) {
					cout << '/' << RREF[i][j].lower;
				}
				cout << ' ';
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cout << RREF[i][j].upper << '/' << RREF[i][j].lower << ' ';
			}
			cout << '\n';
		}
	}
	return;
}

int main() {
	fast_io;

	cin >> row >> col;

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

	// 추가 조건 (원하는 대로)
	// frac_mode == false 이면 분모가 1인걸 정수형으로 출력
	// frac_mode == true 이면 모두 분수형으로 출력
	bool frac_mode = false;
	printRREF(frac_mode);

	return 0;
}