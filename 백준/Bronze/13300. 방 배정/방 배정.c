#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

	int arr[2][6];
	const int student;
	const int maximumStudent;
	scanf("%d %d", &student, &maximumStudent);
	// 성별 & 학년 저장할 2차원 배열

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j] = 0;
		}
	} // 개수를 세기 위해 0으로 초기화

	for (int i = 0; i < student; i++) {
		int gender, grade;
		scanf("%d %d", &gender, &grade);

		arr[gender][grade - 1]++;
	} // 입력 받으면 적절한 위치에 증가

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] % maximumStudent != 0) {
				arr[i][j] = (arr[i][j] / maximumStudent) + 1;
			}
			else {
				arr[i][j] = arr[i][j] / maximumStudent;
			}
		}
	} // 최대 학생 수로 나누었을 때 나머지가 있으면 방 하나 추가, 나누어 떨어지면 그대로

	int total = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			total += arr[i][j];
		}
	} // 각 배열의 원소를 모두 더함

	printf("%d", total);
	return 0;
}