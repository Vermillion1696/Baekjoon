#include <stdio.h>
#include <stdlib.h>

int pow(int a, int b) {
	int total = 1;
	for (int i = 0; i < b; i++) {
		if (b == 0) {
			break;
		}
		else {
			total *= a;
		}
	}
	return total;
	// math.h에 있는 pow와 동일
}
int main(){
	char* arr = (char*)malloc(31 * sizeof(char)); 
	// 2^30 > 10억이므로 NULL 문자 포함 최대 크기가 31

	int b;
	scanf("%s", arr);
	scanf("%d", &b);
	
	int arrlen = 1;
	for (int i = 0; arr[i] != NULL; i++) {
		arrlen++;
	}
	// strlen과 동일한 역할

	long long int sum = 0;
	for(int i = 0; i < arrlen;i++){
		if ((int)arr[i] >= 65 && (int)arr[i] <= 90) {
			sum += ((int)arr[i] - 55) * (pow(b, arrlen - i - 2));
		} // A ~ Z 일 때

		else if ((int)arr[i] >= 48 && (int)arr[i] <= 57) {
			sum += ((int)arr[i] - 48) * (pow(b, arrlen - i - 2));
		} // 0 ~ 9 일 때
	}
	printf("%lld", sum);
	free(arr);
	return 0;
}