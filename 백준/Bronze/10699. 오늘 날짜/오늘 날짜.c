#include <stdio.h>
#include <time.h>
int main(){
	time_t rawtime;
	struct tm* timeinfo;

	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y-%m-%d", timeinfo);
	printf("%s", buffer);

	return 0;
}