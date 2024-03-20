#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		// 횟수 t만큼 테스트 케이스

		int a, b;
		scanf("%d %d", &a, &b);
		// a^b할 숫자 입력
		
		int temp = 1;
		for (int j = 0; j < b; j++) {
			temp *= a;
			if (temp >= 10) {
				temp %= 10;
			}
		}
		// a^b를 담기엔 자료형이 너무 작으므로 % 연산자 이용
		// temp = 1에 a를 반복문 b번 곱하는 형식

		if (temp != 0) {
			printf("%d\n", temp);
		}
		else if (temp == 0) {
			temp = 10;
			printf("%d\n", temp);
		}
		// 나머지가 0일 때 0으로 출력이 되므로 0 -> 10으로 고쳐줌
	}
	return 0;
}