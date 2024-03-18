#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int r;
		scanf("%d", &r);

		char str[21];
		scanf("%s", str);

		int end;

		for (int j = 0; j < 21; j++) {
			if (str[j] == NULL) {
				end = j + 1;
			}
		}

		int length = 0;

		for (int j = 0; j < end - 1; j++) {
			for (int k = 0; k < r; k++) {
				length++;
			}
		}
		//length=9

		int block = 3 * length + 1;

		char* finalstr = (char*)malloc(block * sizeof(char));
		finalstr[block] = NULL;

		for (int j = 0; j < end; j++) {
			for (int k = 0; k < r; k++) {
				finalstr[r * j + k] = str[j];
			}
		}
		printf("%s\n", finalstr);
	}

	return 0;

}