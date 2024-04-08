#include <stdio.h>
#include <string.h>

int main() {
	char str[6];
	char tempstr[6];
	// strncpy를 쓸 tempstr을 만듦

	while (1) {
		scanf("%s", tempstr);
		if (tempstr[0] == '0') {
			break;
		} // 만약 0을 입력 받으면 종료
		else {
			strncpy(str, tempstr, 6);
		} // 0이 아니라면 str에 복사
		// 왜 코드를 이렇게 짜는가? -> str[0] == '0'으로 하면 여러번 입력 받을 때 에러가 나기 때문

		if (strlen(str) == 1) {
			printf("yes\n");
		}
		else {
			int tf = 1; // bool의 역할을 함
			for (int i = 0; i < strlen(str) / 2; i++) {
				if (str[i] != str[strlen(str) - 1 - i]) {
					tf = 0;
				}
			}
			if (tf == 1) {
				printf("yes\n");
			}
			else if (tf == 0) {
				printf("no\n");
			}
		}
	}
	return 0;
}