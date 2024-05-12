#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
	time_t timer;
	struct tm* t;
	timer = time(0);
	t = localtime(&timer);

	printf("%d\n", t->tm_year + 1900);

	if (t->tm_mon >= 9) {
		printf("%d\n", t->tm_mon + 1);
	}
	else {
		printf("0%d\n", t->tm_mon + 1);
	}

	if (t->tm_mday > 9) {
		printf("%d", t->tm_mday);
	}
	else {
		printf("0%d", t->tm_mday);
	}

	return 0;
}