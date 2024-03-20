#include<stdio.h>
#include<stdlib.h>
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		// 테스트 케이스만큼 반복

		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		int** hotel = (int**)malloc(H * sizeof(int*));
		for (int j = 0; j < H; j++) {
			hotel[j] = (int*)malloc(W * sizeof(int));
		}
		// H x W 크기 만큼의 배열 동적 할당

		for (int k = 0; k < W; k++) {
			for (int j = 0; j < H; j++) {
				hotel[j][k] = 0;
			}
		}
		// 각 방의 값을 0으로 초기화

		int temp = 1;
		for (int k = 0; k < W; k++) {
			for (int j = 0; j < H; j++) {
				if (hotel[j][k] == 0) {
					hotel[j][k] = temp;
					temp++;
				}
			}
		}
		// 방이 차는 순서를 값으로 반환하기

		int floor, room;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (hotel[j][k] == N) {
					floor = j + 1;
					room = k + 1;
					printf("%d\n", floor * 100 + room);
				}
			}
		}
		// 손님은 어느 방에 들어가야 하는지 출력하기
	}
	return 0;
}