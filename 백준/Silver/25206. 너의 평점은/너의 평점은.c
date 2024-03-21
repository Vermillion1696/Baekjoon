#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	double point[20];
	double grade[20];
	// 가중치, 성적을 입력받을 double 배열 선언하기
	
	for (int i = 0; i < 20; i++) {
		grade[i] = -1;
	} // 이후에 쓸 조건식을 위해 grade[i]의 모든 원소 -1로 초기화
	
	for (int i = 0; i < 20; i++) {
		int str[51];
		scanf("%s", str); // 과목 이름 받아놓기, 쓸 곳 없으므로 값 저장 X
		scanf("%lf", &point[i]); // 가중치 (학점)

		char temp[3];
		scanf("%s", temp);
		if (temp[1] == '+') {
			for (int j = 0; j < 4; j++) {
				if ((int)temp[0] == j + 65) {
					grade[i] = 4.5 - j;
				}
			}
		} // 2번 칸에 +가 있으면 4.5부터 1.0씩 하강

		else if (temp[1] == '0') {
			for (int j = 0; j < 4; j++) {
				if ((int)temp[0] == j + 65) {
					grade[i] = 4.0 - j;
				}
			}
		} // 2번 칸에 0이 있으면 4.0부터 1.0씩 하강

		else if (temp[0] == 'F') {
			grade[i] = 0;
		} // 1번 칸에 F가 있으면 0.0 반환
	}

	double pointsum = 0;
	double sum = 0;
	// 학점 총합, 학점 x 과목평점을 담을 변수 선언

	for (int i = 0; i < 20; i++) {
		if (grade[i] != -1) {
			pointsum += point[i];
		}
	}
	for (int i = 0; i < 20; i++) {
		if (grade[i] != -1) {
			sum += point[i] * grade[i];
		}
	} // grade[i]가 F가 아니면 (-1) 최종 연산에 포함

	printf("%lf", sum / pointsum);

	return 0;
}