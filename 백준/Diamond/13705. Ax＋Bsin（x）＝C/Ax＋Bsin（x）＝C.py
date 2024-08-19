from decimal import Decimal, getcontext

# 부동 소수점 정밀도 설정
getcontext().prec = 60  # 매우 높은 정밀도로 설정

# pi 값을 문자열로 정확하게 정의
pi = Decimal("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348")

def taylor_sin(x, terms=100):
    """테일러 급수를 이용한 매우 정밀한 sin 계산"""
    x = x % (2 * pi)  # x 값을 0~2pi 범위로 제한
    result = Decimal('0')
    power = x
    factorial = Decimal('1')
    sign = 1

    for n in range(1, terms + 1, 2):
        result += sign * power / factorial
        power *= x * x
        factorial *= Decimal(n + 1) * Decimal(n + 2)
        sign = -sign

    return result

def taylor_cos(x, terms=100):
    """테일러 급수를 이용한 매우 정밀한 cos 계산"""
    x = x % (2 * pi)  # x 값을 0~2pi 범위로 제한
    result = Decimal('1')
    power = x * x
    factorial = Decimal('2')
    sign = -1

    for n in range(2, terms + 1, 2):
        result += sign * power / factorial
        power *= x * x
        factorial *= Decimal(n + 1) * Decimal(n + 2)
        sign = -sign

    return result

def f(x, A, B, C):
    # f(x) = A*x + B*sin(x) - C
    return A * x + B * taylor_sin(x) - C

def df(x, A, B):
    # f'(x) = A + B*cos(x)
    return A + B * taylor_cos(x)

def newton_raphson(A, B, C, tolerance=Decimal('1e-50'), max_iteration=1000000):
    x0 = Decimal('0.0')  # 초기값도 Decimal로 설정
    iteration = 0

    while iteration < max_iteration:
        fx = f(x0, A, B, C)
        dfx = df(x0, A, B)

        if abs(dfx) < Decimal('1e-50'):
            return x0

        x1 = x0 - fx / dfx

        if abs(x1 - x0) < tolerance:
            return x1

        x0 = x1
        iteration += 1

    return x0

if __name__ == "__main__":
    A, B, C = map(Decimal, input().split())  # 입력 값을 Decimal로 변환

    root = newton_raphson(A, B, C)
    print(f"{root:.6f}")  # 소수점 이하 6자리까지 출력
