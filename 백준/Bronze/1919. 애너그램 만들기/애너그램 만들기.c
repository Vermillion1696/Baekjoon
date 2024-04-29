#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[1001];
	char str2[1001];
	int alphabet[26];

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
	
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] != 0) {
			count += abs(alphabet[i]);
		}
	} // 다른 알파벳의 개수 찾기
	
	printf("%d", count);
	
	return 0;
}