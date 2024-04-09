#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void primeNumbers(int a, int b) {
	int* divisions = (int*)malloc(80000 * sizeof(int));
	divisions[0] = 2;
	divisions[1] = -1;
	int lastPlace = 1;
	int tf;
	for (int i = 1; i <= sqrt(b); i += 2) {
		tf = 1;
		for (int j = 0; divisions[j] != -1; j++) {
			if (i % divisions[j] == 0) {
				tf = 0;
				break;
			}
		}
		if (tf == 1 && i > 1) {
			divisions[lastPlace] = i;
			divisions[lastPlace + 1] = -1;
			lastPlace++;
		}
	}
	for (int i = 0; divisions[i] != -1; i++) {
		if (divisions[i] >= a) {
			printf("%d\n", divisions[i]);
		}
	}
	for (int i = a; i <= b; i++) {
		tf = 1;
		for (int j = 0; divisions[j] != -1; j++) {
			if (i % divisions[j] == 0) {
				tf = 0;
				break;
			}
			else if (i < divisions[j]) {
				break;
			}
		}
		if (tf == 1 && i > 1) {
			printf("%d\n", i);
		}
	}
	free(divisions);
	return 0;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	primeNumbers(a, b);
	return 0;
}