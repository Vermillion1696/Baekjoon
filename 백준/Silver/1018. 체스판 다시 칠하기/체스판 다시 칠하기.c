#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b)) 
// 둘 중 더 작은 값을 반환하는 함수 선언

int repaint (int rowStart, int columnStart, char str[50][50]) {
    int repaint = 0;
    for (int i = rowStart; i < rowStart + 8; i++) {
        for (int j = columnStart; j < columnStart + 8; j++) {
            if ((i + j) % 2 == 0) {
                if (str[i][j] != 'B') {
                    repaint++;
                } // 2k 차이 날 때 -> 같은 블럭이어야 함
            }
            else {
                if (str[i][j] != 'W') {
                    repaint++;
                } // 2k + 1 차이 날 때 -> 다른 블럭이어야 함
            }
        }
    }
    return MIN(repaint, 64 - repaint); 
    // 64칸중 칠하는 칸이 더 많을 수도 있으니 64 - repaint와 MIN 함수 적용
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char chess[50][50];

    for (int i = 0; i < a; i++) {
        scanf("%s", chess[i]);
    } // %s로 받은 문자열은 chess[i][j]에 순서대로 저장된다

    int numbers[43][43];
    int min = 65;
    for (int i = 0; i < a - 7; i++) {
        for (int j = 0; j < b - 7; j++) {
            numbers[i][j] = repaint(i, j, chess);
            min = MIN(min, numbers[i][j]);
        }
    } // numbers는 각 위치에 따른 repaint 값의 배열이다

    printf("%d", min);
    return 0;
}