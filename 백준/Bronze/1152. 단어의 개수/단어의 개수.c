#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* str = (char*)malloc(1000000 * sizeof(char));
	scanf("%[^\n]s", str);
	
	int blank = 0;
	int length = 1;
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == ' ') {
			blank++;
		}
		length++;
	}

	int word = blank + 1;
	if (str[0] == ' ') {
		word--;
	}
	if (str[length - 2] == ' ') {
		word--;
	}

	printf("%d", word);
	free(str);
	return 0;
}