#include <stdio.h>
int main() {
	char ahMine[10000];
	char ahDoctor[10000];

	scanf("%s", ahMine);
	scanf("%s", ahDoctor);

	int aMine = 0;
	int aDoctor = 0;
	for (int i = 0; i < 10000; i++) {

		if (ahMine[i] == 'a') {
			aMine++;
		}

		if (ahDoctor[i] == 'a') {
			aDoctor++;
		}
	}

	if (aMine >= aDoctor) {
		printf("go");
	}
	else {
		printf("no");
	}
	
	return 0;
}