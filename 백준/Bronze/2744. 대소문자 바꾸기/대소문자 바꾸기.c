#include <stdio.h>
#include <stdlib.h>
int main() {
	char* str = (char*)malloc(101 * sizeof(char));
	scanf("%s", str);
	for (int i = 0; str[i] != NULL; i++) {
		if ((int)str[i] >= 65 && (int)str[i] <= 90) {
			str[i] += 32;
			printf("%c", str[i]);
		}
		else if ((int)str[i] >= 97 && (int)str[i] <= 122) {
			str[i] -= 32;
			printf("%c", str[i]);
		}
	}
	free(str);
	return 0;
}