#include <iostream>
#include <string>
using namespace std;

int main() {

	// 문자열 받을 sentence, 모음 개수 받을 count
	string sentence;
	int count = 0;
	
	while (1) {

		// <string> library 내장 getline 함수, \n을 포함해서 문자열을 받는다
		getline(cin, sentence);

		// <iostream> library 내장 compare 함수, C99 <string.h>의 strcmp 함수와 동일하다
		if (sentence.compare("#") == 0) {
			break;
		}
		else {
			for (int i = 0; sentence[i] != NULL; i++) {
				if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {
					count++;
				}
			}

			// 출력 후 초기화
			cout << count << endl;
			count = 0;
		}
	}
}