#include <stdio.h>
int main() {
	char chess[8][9];
	for (int i = 0; i < 8; i++) {
		scanf("%s", chess[i]);
	}

	int times = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i][j] == 'F') {
				if ((i + j) % 2 == 0) {
					times++;
				}
			}
		}
	}

	printf("%d", times);
}