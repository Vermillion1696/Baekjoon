#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int n;
	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		// n<=9999 이므로 arr[4]에 modulo 10 연산자 적용 결과 저장
		int arr[4];
		int numCnt = 0;
		for (int i = 0; i < 4; i++) {
			if (n /= 10 > 0) {
				arr[i] = n % 10;
				n /= 10;
				numCnt++;
			}
			else {
				arr[i] = -1;
			}
		}

		// 글자에 따른 길이 할당
		int length = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[i] == 1) {
				length += 2;
			}
			else if (arr[i] == 0) {
				length += 4;
			}
			else if(arr[i] != -1){
				length += 3;
			}
		}

		// 글자 수 + 1 만큼 빈칸 추가
		length += (numCnt + 1);
		printf("%d\n", length);
	}

	return 0;
}