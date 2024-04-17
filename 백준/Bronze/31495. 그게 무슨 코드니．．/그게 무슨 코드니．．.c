#include <stdio.h>
#include <string.h>
int main() {
	char str[51];
	scanf("%[^\n]", str);

	int count = 0;
	int from = -1;
	int to = -1;
	for (int i = 0; i < 51; i++) {
		if (str[i] == '\"') {
			count++;
			if (count == 1) {
				from = i;
			}
			else {
				to = i;
			}
		}
	} // from, to에 어디부터 어디까지 저장할지 체크
	// count는 큰따옴표의 개수 카운트
	
	int tf1 = 1;
	for (int i = from + 1; i < to; i++) {
		if (str[i] != ' ') {
			tf1 = 0;
		}
	} // 큰따옴표 내부가 빈 문자열이면 tf = 0

	if (count == 2 && tf1 == 0 && strlen(str) - 1 == to - from) {
		for (int i = from + 1; i < to; i++) {
			printf("%c", str[i]);
		} // 큰따옴표 다음부터 큰따옴표 전까지 출력
	} // 문자열 길이 - 1 = to - from 이면 큰따옴표 뒤에 뭐가 없다
	else {
		printf("CE");
	}

	return 0;
}