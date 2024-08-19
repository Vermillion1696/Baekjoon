# 위 코드는 C++로 제가 작성한 11729 하노이 탑 이동 순서 코드를 python으로 전환한 코드입니다.
# http://boj.kr/1fbc2707de3b4836ab3c875aae9b76aa

import sys

# 빠른 입출력을 위한 설정
input = sys.stdin.read
sys.setrecursionlimit(10**6)

def hanoi(from_pos, to_pos, via_pos, cnt):
    # 이동 개수가 1개인 경우
    if cnt == 1:
        print(from_pos, to_pos)
    # 이동 개수가 1개 이상인 경우
    else:
        # cnt - 1개를 from_pos -> via_pos
        hanoi(from_pos, via_pos, to_pos, cnt - 1)
        
        # 1개를 from_pos -> to_pos (제일 큰 것)
        print(from_pos, to_pos)
        
        # cnt - 1개를 via_pos -> to_pos
        hanoi(via_pos, to_pos, from_pos, cnt - 1)

def main():
    n = int(input().strip())
    x, y, z = 1, 2, 3

    # 2^n - 1을 계산 (C++의 비트 연산자와 동일하게 동작)
    print((1 << n) - 1)
    
    if n <= 20:
        hanoi(x, z, y, n)

if __name__ == "__main__":
    main()
