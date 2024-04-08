#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strChange(char str1[51], char str2[51]) {
    char tempStr[51];
    strncpy(tempStr, str1, 51);
    strncpy(str1, str2, 51);
    strncpy(str2, tempStr, 51);
}

int partition(char str[20000][51], int left, int right) {
    char pivot[51];
    strcpy(pivot, str[right]);
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (strlen(str[j]) < strlen(pivot) || (strlen(str[j]) == strlen(pivot) && strcmp(str[j], pivot) <= 0)) {
            i++;
            strChange(str[i], str[j]);
        }
    }

    strChange(str[i + 1], str[right]);
    return i + 1;
}

void quickSort(char str[20000][51], int left, int right) {
    if (left < right) {
        int partitionIndex = partition(str, left, right);
        quickSort(str, left, partitionIndex - 1);
        quickSort(str, partitionIndex + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char str[20000][51];

    for (int i = 0; i < n; i++) {
        char temp[51];
        scanf("%s", temp);
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(temp, str[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            i--;
            n--;
        }
        else {
            strncpy(str[i], temp, 51);
        }
    }

    quickSort(str, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}