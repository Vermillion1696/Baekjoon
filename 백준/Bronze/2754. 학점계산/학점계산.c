#include <stdio.h>
int main() {
	char arr[2];
	scanf("%c", &arr[0]);
	scanf("%c", &arr[1]);
	for (int i = 0; i < 4; i++) {
		if ((int)arr[0] == 65 + i) {
			if (arr[1] == '+') {
				printf("%.1lf", 4.3 - i);
			}
			else if (arr[1] == '0') {
				printf("%.1lf", 4.0 - i);
			}
			else {
				printf("%.1lf", 3.7 - i);
			}
		}
		else if (arr[0] == 'F') {
			printf("%.1lf", 0.0);
			break;
		}
	}
	return 0;
}