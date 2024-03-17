
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* str = (char*)malloc(1000 * sizeof(char));
	scanf("%s", str);
	
	for (int i = 0; i < 1000; i++) {
		if (str[i] == '\0') {
			printf("%d", i);
			break;
		}
	}
}