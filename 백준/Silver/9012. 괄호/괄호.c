#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	int times;
	scanf("%d", &times);

	char str[51];
	for (int i = 0; i < times; i++) {
		scanf("%s", str);

		int tf = 1;
		// bool 역할

		if (strlen(str) % 2 == 1) {
			tf = 0;
		} // strlen(str)이 홀수면 괄호의 짝이 어차피 안 맞으므로 false

		int count = 0;

		if (tf != 0) {
			for (int i = 0; i <= strlen(str); i++) {
				if (str[i] == '(') {
					count++;
				}
				else if (str[i] == ')') {
					count--;

					if (count < 0) {
						tf = 0;
						break;
					} // str[0]부터 카운트 하는데 ( 개수 < ) 개수이면 false
				}
			}
			
			if (count != 0) {
				tf = 0;
			} // 개수가 다르면 false
		}

		if (tf == 1) {
			printf("YES\n");
		}
		else if (tf == 0) {
			printf("NO\n");
		}
	}

	return 0;
}