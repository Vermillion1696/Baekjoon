#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* arr = (char*)malloc(101 * sizeof(char));
	scanf("%s", arr);

	int whereNull = 1;
	for (int i = 0; arr[i] != NULL; i++) {
		whereNull++;
	} // whereNull번째 칸에 NULL이 있음

	int tf = 1;
	for (int i = 0; i < (whereNull - 1) / 2; i++) {
		if (arr[i] != arr[whereNull - 2 - i]) {
			tf = 0;
		}
	}

	printf("%d", tf);
	
	return 0;
}