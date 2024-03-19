#include<stdio.h>
#include<stdlib.h>
int main() {
	char* str = (char*)malloc(1000001 * sizeof(char));
	scanf("%s", str);
	// 단어의 길이가 1,000,000을 넘지 않는 배열

	for (int i = 0; str[i] != NULL; i++) {
		if ((int)str[i] >= 97 && (int)str[i] <= 122) {
			str[i] -= 32;
		}
	}
	// 소문자를 모두 대문자로 바꿔줌
	
	int alphabet[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}
	// 횟수를 적을 배열 선언, 0으로 초기화

	for (int i = 0; str[i] != NULL; i++) {
		for (int j = 0; j < 26; j++) {
			if ((int)str[i] == j + 65) {
				alphabet[j] += 1;
			}
		}
	}
	// 각 문자 검사 후 횟수 ++ 시키기

	int max = -1;
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
		}
	}
	// 횟수를 적은 배열에서 가장 많이 나온 횟수 찾기

	int times = 0;
	int where;
	for (int i = 0; i < 26; i++) {
		if (max == alphabet[i]) {
			times++;
			where = i;
		}
	}
	// max번 나온 알파벳이 몇 개인지 찾기
	
	if (times == 1) {
		printf("%c", where + 65);
	}
	else if (times != 1) {
		printf("?");
	}
	// max가 여러번이면 ?, max가 한 번이면 문자 출력

	return 0;
}