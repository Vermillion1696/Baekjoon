#include<stdio.h>

int main() {
    char let;
    while (scanf("%c", &let) != EOF) {
        printf("%c", let);
    }
    return 0;
}