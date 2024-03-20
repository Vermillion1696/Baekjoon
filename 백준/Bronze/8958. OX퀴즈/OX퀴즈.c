#include<stdio.h>
#include<stdlib.h>
int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int i = 0; i < caseNum; i++) {
		// 테스트 케이스의 개수 입력 받기

		char* arr = (char*)malloc(81 * sizeof(char));
		scanf("%s", arr);
		// 테스트 케이스 문자열 만들기

		int sum = 0;
		int currentScore = 1;
		for (int j = 0; arr[j] != NULL; j++) {
			if (arr[j] == 'O') {
				sum += currentScore;
				currentScore++;
			}
			else if (arr[j] == 'X') {
				currentScore = 1;
			}
		}
		printf("%d\n", sum);
		// 총 점수 계산
	}
	return 0;
}