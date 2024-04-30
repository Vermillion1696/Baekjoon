#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    } // 오름차순이면 True

    else if (*(int*)a < *(int*)b) {
        return -1;
    } // 내림차순이면 False

    else {
        return 0;
    } // 아니면 종료

} // 오름차순 정리 비교 함수, qsort() 라이브러리 사용에 쓰인다

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    } // 배열 값 입력

    qsort(arr, n, sizeof(int), compare);
    // 퀵정렬

    int total = 0;
    int tempSum = 0;

    for (int i = 0; i < n; i++) {
        tempSum = 0;
        for (int j = 0; j <= i; j++) {
            tempSum += arr[j];
        }
        total += tempSum;
    } // tempSum은 arr[0]부터 arr[j]까지의 합
    // total은 각 tempSum의 합

    printf("%d", total);
    
    free(arr);
    return 0;
}