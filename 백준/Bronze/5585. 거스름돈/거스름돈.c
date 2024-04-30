#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int money;
	scanf("%d", &money);
	money = 1000 - money;

	int cnt = 0;
	while (money >= 500) {
		money -= 500;
		cnt++;
	}
	while (money >= 100) {
		money -= 100;
		cnt++;
	}
	while (money >= 50) {
		money -= 50;
		cnt++;
	}
	while (money >= 10) {
		money -= 10;
		cnt++;
	}
	while (money >= 5) {
		money -= 5;
		cnt++;
	}
	cnt += money;

	printf("%d", cnt);
	return 0;
}