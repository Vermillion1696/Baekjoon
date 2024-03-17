
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* str = (char*)malloc(1000 * sizeof(char));
	scanf("%s", str);
	
	int n;
	scanf("%d", &n);

	printf("%c", str[n - 1]);
}