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
    int count;
    int i, j;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    } // 배열 값 입력

    int x;
    scanf("%d", &x);

    count = 0;
    qsort(arr, n, sizeof(int), compare);
    // <stdlib.h> 내장 quickSort 함수, 필요 요소 : 배열, 원소 개수, 자료형, compare 함수

    i = 0;
    j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
        { // 케이스 1. 값이 같을 때

            count++;
            // 카운트 증가

            if (arr[i + 1] - arr[i] < arr[j] - arr[j - 1])
            {
                i++;
            }
            else
            {
                j--;
            } // sum과의 차이가 적은 쪽으로 증가 시킴 (배열이 정렬되어 있으므로)
        }
        else if (arr[i] + arr[j] > x)
        { // 케이스 2. 더한 값이 더 클 때 -> 끝점 포인터 감소
            j--;
        }
        else if (arr[i] + arr[j] < x)
        { // 케이스 3. 더한 값이 더 작을 때 -> 시작점 포인터 증가
            i++;
        } // 왜 이게 되는가 ? -> 배열이 정렬 되어 있으므로
        // 합이 더 크다? 끝점 감소 -> 합 감소
        // 합이 더 작다? 시작점 증가 -> 합 증가
        // 위치가 동일하다면 셋 중 어떤 케이스가 되더라도 i < j가 0이 되므로 while 탈출
    }
    free(arr);
    printf("%d\n", count);
}