#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 두 개의 서브 배열을 병합하는 함수
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // 임시 배열들을 생성합니다.
    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    // 두 개의 서브 배열을 임시 배열로 복사합니다.
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 임시 배열들을 병합하여 원래 배열에 저장합니다.
    i = 0; // 첫 번째 서브 배열의 인덱스
    j = 0; // 두 번째 서브 배열의 인덱스
    k = l; // 병합된 배열의 시작 인덱스
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 복사합니다.
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// 병합 정렬 알고리즘을 구현하는 함수
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // 첫 번째 반쪽을 정렬합니다.
        mergeSort(arr, l, m);
        // 두 번째 반쪽을 정렬합니다.
        mergeSort(arr, m + 1, r);

        // 두 개의 정렬된 배열을 병합합니다.
        merge(arr, l, m, r);
    }
}

int arr[1010101]; // 배열의 크기가 크므로 main 밖에서 선언

// 메인 함수
int main() {
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);
    // 병합 정렬 정의한 식 사용

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
