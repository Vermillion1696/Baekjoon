#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// Profile 구조체 : weight -> 무게, height -> 키, point -> 점수, grade -> 등수
	typedef struct {
		int weight[50];
		int height[50];
		int point[50];
		int grade[50];
	} Profile;

	Profile member;

	// 점수를 0으로 초기화
	for (int i = 0; i < 50; i++) {
		member.point[i] = 1;
	}

	// 각 멤버의 인적사항 받기
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &member.weight[i], &member.height[i]);
	}

	// 키도 작고 무게도 가벼울 때만 point ++
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (member.weight[i] > member.weight[j] && member.height[i] > member.height[j]) {
				member.point[j]++;
			}
			else if (member.weight[i] < member.weight[j] && member.height[i] < member.height[j]) {
				member.point[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d", member.point[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}

	return 0;
}