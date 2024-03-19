#include<stdio.h>

int main() {
    char str[16];
    int time = 0;
    scanf("%s", str);

    for (int i = 0; str[i] != NULL; i++) {
        if (65 <= (int)str[i] && (int)str[i] <= 67) {
            time += 3;
        }
        else if (68 <= (int)str[i] && (int)str[i] <= 70) {
            time += 4;
        }
        else if (71 <= (int)str[i] && (int)str[i] <= 73) {
            time += 5;
        }
        else if (74 <= (int)str[i] && (int)str[i] <= 76) {
            time += 6;
        }
        else if (77 <= (int)str[i] && (int)str[i] <= 79) {
            time += 7;
        }
        else if (80 <= (int)str[i] && (int)str[i] <= 83) {
            time += 8;
        }
        else if (84 <= (int)str[i] && (int)str[i] <= 86) {
            time += 9;
        }
        else if (87 <= (int)str[i] && (int)str[i] <= 90) {
            time += 10;
        }
    }
    printf("%d", time);
    return 0;
}