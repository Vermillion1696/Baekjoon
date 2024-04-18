#include <stdio.h>
int main() {
	int n;
	int y = 0; 
	int m = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		y += ((temp / 30) + 1) * 10;
		m += ((temp / 60) + 1) * 15;
	} // y는 30초마다 10원씩, m은 60초마다 15원씩
	
	if (y == m) {
		printf("Y M %d", y);
	}
	else if (y < m) {
		printf("Y %d", y);
	}
	else if (y > m) {
		printf("M %d", m);
	} // 분기점을 갈라서 출력

	return 0;
}