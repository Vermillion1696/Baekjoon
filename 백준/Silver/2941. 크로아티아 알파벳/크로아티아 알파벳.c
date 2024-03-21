#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* arr = (char*)malloc(101 * sizeof(char));
	scanf("%s", arr);

	int times = 0;
	for (int i = 0; arr[i] != NULL; i++) {
		times++;
	}

	for (int i = 0; arr[i + 1] != NULL; i++) {
		if (arr[i] == 'c' && arr[i + 1] == '=' || arr[i] == 'c' && arr[i + 1] == '-' || arr[i] == 'd' && arr[i + 1] == '-' || arr[i] == 'l' && arr[i + 1] == 'j' || arr[i] == 'n' && arr[i + 1] == 'j' || arr[i] == 's' && arr[i + 1] == '=' || arr[i] == 'z' && arr[i + 1] == '=') {
			times--;
		}
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') {
			times--;
		}
	}
	printf("%d", times);
	return 0;
}