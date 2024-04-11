#include <stdio.h>
#include <string.h>
#include <math.h> // pow 라이브러리

int returnValue(char str[]) {
	if (strcmp(str, "black") == 0) {
		return 0;
	}
	else if (strcmp(str, "brown") == 0) {
		return 1;
	}
	else if (strcmp(str, "red") == 0) {
		return 2;
	}
	else if (strcmp(str, "orange") == 0) {
		return 3;
	}
	else if (strcmp(str, "yellow") == 0) {
		return 4;
	}
	else if (strcmp(str, "green") == 0) {
		return 5;
	}
	else if (strcmp(str, "blue") == 0) {
		return 6;
	}
	else if (strcmp(str, "violet") == 0) {
		return 7;
	}
	else if (strcmp(str, "grey") == 0) {
		return 8;
	}
	else {
		return 9;
	}
}
// strcmp로 문자열 비교 후 각 값에 맞는 integer 반환

int main() {

	char str[7];
	long long int total = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%s", str);
		if (i == 0) {
			total += returnValue(str) * 10;
		}
		else if (i == 1) {
			total += returnValue(str);
		}
		else {
			total *= pow(10, returnValue(str));
		}
	} 
	// 1, 2번은 각각 10의 자리, 1의 자리
	// 3번은 10^n 곱하기
	
	printf("%lld", total);
	return 0;
}