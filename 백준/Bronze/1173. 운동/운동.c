#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 운동 함수
void exercise(int minRate, int maxRate, int rateIncrease, int* rateCurrent, int* exerciseCurrent, int* timeCurrent, int exerciseNeeded) {
	while (*rateCurrent <= maxRate - rateIncrease) {
		*rateCurrent += rateIncrease;
		(*exerciseCurrent)++;
		(*timeCurrent)++;
		
		// 중간에 exerciseCurrent == exerciseNeeded가 되면 break
		if (*exerciseCurrent >= exerciseNeeded) {
			break;
		}
	}
}

// 휴식 함수
void breaktime(int minRate, int maxRate, int rateDecrease, int* rateCurrent, int* timeCurrent) {
	if (*rateCurrent - rateDecrease < minRate) {
		*rateCurrent = minRate;
		(*timeCurrent)++;
	}
	else {
		*rateCurrent -= rateDecrease;
		(*timeCurrent)++;
	}
}

int main() {
	
	// 총 운동 필요 분, 최소 맥박, 최대 맥박, 운동시 분당 증가량, 휴식시 분당 감소량
	int exerciseNeeded, minRate, maxRate, rateIncrease, rateDecrease;
	scanf("%d %d %d %d %d", &exerciseNeeded, &minRate, &maxRate, &rateIncrease, &rateDecrease);

	// 현재 운동 총 시간, 현재 총 지난 시간
	int exerciseCurrent = 0;
	int timeCurrent = 0;

	// maxRate와 minRate의 차이보다 운동시 증가 맥박 (rateIncrease)가 크면 불가능 판정
	if (maxRate - minRate < rateIncrease) {
		printf("-1");
		return 0;
	}
	else {

		// 시작 맥박 minRate
		int rateCurrent = minRate;

		// 현재 운동 총량 < 필요 운동 양 일때 반복문
		while (exerciseCurrent < exerciseNeeded) {
			if (rateCurrent + rateIncrease <= maxRate) {
				exercise(minRate, maxRate, rateIncrease, &rateCurrent, &exerciseCurrent, &timeCurrent, exerciseNeeded);
			}
			else {
				breaktime(minRate, maxRate, rateDecrease, &rateCurrent, &timeCurrent);
			}
		}
	}

	printf("%d", timeCurrent);
	return 0;
}