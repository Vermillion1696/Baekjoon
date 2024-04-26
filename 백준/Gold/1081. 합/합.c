#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int pow(int a, int b) {
    int total = 1;
    if (b == 0) {
        return total;
    }
    else {
        for (int i = 0; i < b; i++) {
            total *= a;
        }
        return total;
    }
}

long long int recursive(int n) {
    long long int total = 0;
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 45;
    }
    else {
        for (int i = 0; i <= 9; i++) {
            total += i * pow(10, n - 1);
        }
        total += recursive(n - 1) * 10;
    }
    return total;
} // 0 ~ 999...999 (n 자리) 까지 각 자리 숫자의 합

int main() {

    long long int a, b;
    scanf("%lld %lld", &a, &b);

    long long int tempA = a;
    long long int tempB = b;

    int arrA[10];
    int arrB[10];
    for (int i = 0; i <= 9; i++) {
        arrA[i] = tempA % 10;
        arrB[i] = tempB % 10;
        tempA /= 10;
        tempB /= 10;
    } // 배열에 자리수(오름차순)대로 정렬

    int count1 = 0;
    int count2 = 0;
    for (int i = 1; i <= 10; i++) {
        if (arrA[i - 1] != 0) {
            count1 = i;
        }
    }
    for (int i = 1; i <= 10; i++) {
        if (arrB[i - 1] != 0) {
            count2 = i;
        }
    } // 제일 큰 자릿수가 무엇인지 count1, count2에 저장

    long long int sum1 = 0;
    int numAdder = 0;

    for (int k = 1; k < count1; k++) {
        sum1 += recursive(count1 - k) * arrA[count1 - k];
        // recursive를 앞 자리수 만큼 (ex. 0~499 -> 0~99까지의 합 4번 + @ : recursive(2) 4번)

        for (int i = 0; i < arrA[count1 - k]; i++) {
            sum1 += pow(10, count1 - k) * i;
            sum1 += pow(10, count1 - k) * numAdder;
        }

        numAdder += arrA[count1 - k];
        // 자릿수 깎아 내릴 때 numAdder를 연산에 포함

    }
    // ex. 0 ~ 33 -> 0 ~ 9 + 10 ~ 19 + 20 ~ 29 + 30 ~ 33
    // -> (recursive(1) + 0이 10번 등장) + (recursive(1) + 1이 10번 등장)
    // + (recursive(1) + 2가 10번 등장) + (recursive(1) + 3이 10번 등장) + 30 ~ 33
    // -> 4 * recursive(1) + 10 * Sigma(i from 0 to 3) i + 30 ~ 33

    int times = arrA[0] + 1;
    // ex. 30 ~ 33을 구하기 위해서 -> 이때 times = 4

    int allNumSum = 0;
    for (int i = 0; i < count1; i++) {
        allNumSum += arrA[i];
    }
    allNumSum -= arrA[0];
    // 마지막 자리를 제외한 각 자리 숫자의 합

    sum1 += (allNumSum * times);

    for (int i = 0; i < times; i++) {
        sum1 += i;
    }

    long long int sum2 = 0;
    numAdder = 0;

    for (int k = 1; k < count2; k++) {
        sum2 += recursive(count2 - k) * arrB[count2 - k];
        // recursive를 앞 자리수 만큼 (ex. 0~499 -> 0~99까지의 합 4번 + @ : recursive(2) 4번)

        for (int i = 0; i < arrB[count2 - k]; i++) {
            sum2 += pow(10, count2 - k) * i;
            sum2 += pow(10, count2 - k) * numAdder;
        }

        numAdder += arrB[count2 - k];
        // 자릿수 깎아 내릴 때 numAdder를 연산에 포함

    }
    // ex. 0 ~ 33 -> 0 ~ 9 + 10 ~ 19 + 20 ~ 29 + 30 ~ 33
    // -> (recursive(1) + 0이 10번 등장) + (recursive(1) + 1이 10번 등장)
    // + (recursive(1) + 2가 10번 등장) + (recursive(1) + 3이 10번 등장) + 30 ~ 33
    // -> 4 * recursive(1) + 10 * Sigma(i from 0 to 3) i + 30 ~ 33

    times = arrB[0] + 1;
    // ex. 30 ~ 33을 구하기 위해서 -> 이때 times = 4

    allNumSum = 0;
    for (int i = 0; i < count2; i++) {
        allNumSum += arrB[i];
    }
    allNumSum -= arrB[0];
    // 마지막 자리를 제외한 각 자리 숫자의 합

    sum2 += (allNumSum * times);

    for (int i = 0; i < times; i++) {
        sum2 += i;
    }

    for (int i = 0; i <= 9; i++) {
        sum1 -= arrA[i];
    } // sum2 - sum1을 할 때 sum1이 값에 포함이 되도록 sum1 수를 다시 더해 줌

    printf("%lld", sum2 - sum1);
    return 0;
}