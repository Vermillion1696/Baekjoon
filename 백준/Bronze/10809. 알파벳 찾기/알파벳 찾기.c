#include<stdio.h>
#include<stdlib.h>

int main()
{
	char word[101];
	int alphabet[26];

	for (int i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}

	scanf("%s", word);

	int endnum;

	for (int i = 0; i < 101; i++) {
		if (word[i] == NULL) {
			endnum = i - 1;
			break;
		}
	}

	while (endnum >= 0) {
		for(int i = 0; i < 26; i++) {
			if ((int)word[endnum] == 97 + i) {
				alphabet[i] = endnum;
			}
		}
		endnum--;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	
	return 0;

}