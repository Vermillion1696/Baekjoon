#include <stdio.h>
int main() {
	int times;
	scanf("%d", &times);
	for (int i = 0; i < times; i++) {

		int cent;
		scanf("%d", &cent);

		int quarter = 0;
		int dime = 0;
		int nikkel = 0;
		int penny = 0;

		while (cent >= 25) {
			cent -= 25;
			quarter++;
		}
		while (cent >= 10) {
			cent -= 10;
			dime++;
		}
		while (cent >= 5) {
			cent -= 5;
			nikkel++;
		}
		penny = cent;

		printf("%d %d %d %d\n", quarter, dime, nikkel, penny);
	}
	return 0;
}