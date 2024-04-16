#include <stdio.h>
#include <string.h>
int main() {
	char str[5][16];
	int length[5];

	for (int i = 0; i < 5; i++) {
		scanf("%s", str[i]);
		length[i] = strlen(str[i]);
	} // str에 문자열 입력, length에 문자열의 길이 입력

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (length[i] > 0) {
				printf("%c", str[i][j]);
				length[i]--;
			}
		}
	} // 각 글자를 출력할 때마다 문자열의 길이 -1씩, 0보다 클때만 출력
	return 0;
}