#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t;
	int word = 0;
	scanf("%d", &t);
	// 반복문 돌릴 횟수, 단어 개수 셀 변수 선언

	for (int i = 0; i < t; i++) {
		char* str = (char*)malloc(101 * sizeof(char));
		scanf("%s", str);
		// max 100칸 + NULL문자 선언

		int checker1 = 1;
		int checker2 = 0;
		// str[i] != str[i+1] 세는 checker1
		// 사용된 문자 개수 세는 checker2

		int whenNull = 0;
		for (int q = 0; str[q] != NULL; q++) {
			whenNull++;
		}
		// Null 문자는 몇번째로 오는지

		if (whenNull == 1) {
			word++;
		}
		// str이 1글자면 checker1이 오류가 나므로 예외처리

		else if (whenNull != 1) {
			for (int j = 0; str[j + 1] != NULL; j++) {
				if (str[j] != str[j + 1]) {
					checker1++;
				}
			}

			int alphabet[26];
			for (int j = 0; j < 26; j++) {
				alphabet[j] = 0;
			}
			// 사용된 문자 적어놓을 배열 alphabet 선언 후 초기화

			for (int j = 0; str[j] != NULL; j++) {
				for (int k = 0; k < 26; k++) {
					if ((int)str[j] == 97 + k) {
						alphabet[k] = 1;
					}
				}
			}
			// 사용된 알파벳은 배열 안 값을 0 -> 1로 바꿈

			for (int k = 0; k < 26; k++) {
				if (alphabet[k] == 1) {
					checker2++;
				}
			}
			// 1의 개수를 세어 checker2에 넣음

			if (checker1 == checker2) {
				word++;
			}
			// checker1 == checker2면 그룹 단어가 true
		}
		free(str);
	}
	printf("%d", word);
	return 0;
}