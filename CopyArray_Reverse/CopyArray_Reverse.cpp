﻿//==========================================================
//	配列の反転コピー 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void CopyArrayReverse(int srcArray[], int dstArray[], int arraySize);
void setRandomArray(int array[], int arraySize);
void dumpArray(int array[], int arraySize);

int main()
{
    srand(time(NULL));
    int size;
    do {
        printf("要素数:");
        scanf("%d", &size);
    } while (size <= 0);

    int* a = (int*)calloc(size, sizeof(int));
    int* b = (int*)calloc(size, sizeof(int));
    if (a == nullptr || b == nullptr) {
        printf("calloc失敗\n");
        exit(1);
    }

    setRandomArray(a, size);
    setRandomArray(b, size);
    printf("a[]は\n");
    dumpArray(a, size);
    printf("b[]は\n");
    dumpArray(b, size);

    CopyArrayReverse(a, b, size);
    printf("\na[]をb[]へ反転コピーしました\n");
    printf("a[]は\n");
    dumpArray(a, size);
    printf("b[]は\n");
    dumpArray(b, size);

    free(a);
    free(b);
    return 0;
}

void CopyArrayReverse(int srcArray[], int dstArray[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        dstArray[i] = srcArray[arraySize - 1 - i];
    }
}

void setRandomArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 1000;
    }
}

void dumpArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

