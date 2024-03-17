
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char* str = (char*)malloc(1000 * sizeof(char));
		scanf("%s", str);

		for (int j = 0; j < 1000; j++) {
			if (str[j] == '\0') {
				printf("%c%c\n", str[0], str[j - 1]);
				break;
			}
		}
		free(str);
	}
}