#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int testCase;
	scanf("%d", &testCase);
	// 테스트 케이스

	char str1[1001];
	char str2[1001];
	int alphabet[26];
	for (int i = 0; i < testCase; i++) {
		scanf("%s", str1);
		scanf("%s", str2);
		for (int i = 0; i < 26; i++) {
			alphabet[i] = 0;
		} // 배열 초기화

		for (int i = 0; i < strlen(str1); i++) {
			for (int j = 0; j < 26; j++) {
				if (str1[i] == 97 + j) {
					alphabet[j]++;
					break;
				}
			}
		} // str1에 있는 알파벳 개수 (양수)

		for (int i = 0; i < strlen(str2); i++) {
			for (int j = 0; j < 26; j++) {
				if (str2[i] == 97 + j) {
					alphabet[j]--;
					break;
				}
			}
		} // str2에 있는 알파벳 개수 (음수)

		int tf = 1;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] != 0) {
				tf = 0;
				break;
			}
		} // 전부 0이면 strfry가 가능

		if (tf == 1) {
			printf("Possible\n");
		}
		else {
			printf("Impossible\n");
		}
	}
	return 0;
}