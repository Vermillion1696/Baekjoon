#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char str[60];
    scanf("%s", str);

    int countX = 0;
    int tf = 1;
    for (int i = 0; i < strlen(str) + 1; i++) {
        if (str[i] == 'X') {
            countX++;
            str[i] = 'A';
        } // X를 A로 바꾸며 X의 개수를 카운트
        else {
            if (countX % 2 == 1) {
                tf = 0;
                break;
            } // X 개수가 홀수면 AAAA, BB로는 채울 수 없으므로 불가능 판정
            else if (countX % 4 != 0) {
                str[i - 1] = 'B';
                str[i - 2] = 'B';
            } // X의 개수가 4로 나누어 떨어지지 않고 홀수가 아니면 B가 들어갈 자리
            countX = 0;
        }
    }

    if (tf == 1) {
        printf("%s", str);
    }
    else {
        printf("-1");
    } // 가능하면 출력, 불가능이면 -1

    return 0;
}