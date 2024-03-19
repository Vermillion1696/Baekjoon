#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swapTwo(int arr[]) {
	int temp;
	temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;
	return 0;
}

int ASCIIchanger(int i, char str[]) {
	for (int j = 0; j < 10; j++) {
		if ((int)str[i] == j + 48) {
			return j;
		}
	}
}

int compareNresult(int str1[], int str2[]) {
	for (int i = 0; i < 3; i++) {
		if (str1[i] > str2[i]) {
			int temp = str1[0] * 100 + str1[1] * 10 + str1[2];
			return temp;
		}
		else if (str1[i] < str2[i]) {
			int temp = str2[0] * 100 + str2[1] * 10 + str2[2];
			return temp;
		}
	}
}

int main() {

	int str1[3];
	int str2[3];

	for (int i = 0; i < 2; i++) {
		char str[4];
		int newstr[3];
		scanf("%s", str);

		for (int j = 0; j < 3; j++) {
			newstr[j] = ASCIIchanger(j, str);
			if (i == 0) {
				str1[j] = newstr[j];
				swapTwo(str1);
			}
			else {
				str2[j] = newstr[j];
				swapTwo(str2);
			}
		}
	}

	int whichone = compareNresult(str1, str2);
	printf("%d", whichone);
	return 0;
}