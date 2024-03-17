#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	char* str = (char*)malloc(n * sizeof(char));
	scanf("%s", str);

	int sum = 0;

	for (int i = 0; i < n; i++) {
		
		int temp = 0;
		temp = str[i] - 48;
		sum += temp;

	}

	printf("%d", sum);
	return 0;

}