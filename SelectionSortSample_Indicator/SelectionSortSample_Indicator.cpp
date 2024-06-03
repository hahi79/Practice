﻿//=========================================================
//	単純選択ソート 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void SelectionSort(int array[], int arraySize);
void indicator(int top, int min, int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int main()
{
	srand(time(NULL));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		SelectionSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void SelectionSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arraySize; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		indicator(i, min, array, arraySize);
		if (min != i) {
			swap(int, array[i], array[min]);
		}
	}
}

void indicator(int top, int min, int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		const char* mark = "";
		if (i == top) {
			mark = (i == min) ? "*+" : "*";
		}
		else if (i == min) {
			mark = "+";
		}
		printf("%4s", mark);
	}
	putchar('\n');
	for (int i = 0; i < arraySize; i++) {
		printf("%4d", array[i]);
	}
	putchar('\n');
}

void dumpArray(const int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}

