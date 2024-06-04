//=========================================================
//	クイックソート　Stack最適化
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include "IntStack.h"
// 関数プロトタイプ
void QuickSort_Recursive(int array[], int left, int right);
void QuickSort_NotRecursive(int array[], int left, int right);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);
// 交換マクロ
#define swap(type,a,b)   do{ type tmp=a; a=b; b=tmp; }while(false)

int main()
{
	srand(time(NULL));
	int arraySize;
	int* array;
	int* array2;

	while (true) {
		do {
			printf("要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		array2 = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr || array2 == nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = array2[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		QuickSort_Recursive(array,0, arraySize-1);
		QuickSort_NotRecursive(array2, 0, arraySize - 1);
		printf("昇順にソートしました\n");
		dumpArray(array2, arraySize);

		free(array2);
		free(array);
	}
	return 0;
}

void QuickSort_Recursive(int array[], int left, int right)
{
	int pl = left;
	int pr = right;
	int x = array[(left + right) / 2];

	do {
		while (array[pl] < x) pl++;
		while (array[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	int L1 = left;
	int R1 = pr;
	int L2 = pl;
	int R2 = right;
	if (R1 - L1 > R2 - L2) {
		swap(int, R1, R2);
		swap(int, L1, L2);
	}
	if (L1 < R1) QuickSort_Recursive(array, L1, R1);
	if (L2 < R2) QuickSort_Recursive(array, L2, R2);
}

void QuickSort_NotRecursive(int array[], int left,int right)
{
	IntStack stk;
	Initialize(&stk, right - left + 1);

	Push(&stk, left);
	Push(&stk, right);
	while (IsEmpty(&stk) == false) {
		Pop(&stk, &right);
		Pop(&stk, &left);
		int pl = left;
		int pr = right;
		int x = array[(left + right) / 2];
		do {
			while (array[pl] < x) pl++;
			while (array[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, array[pl], array[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);
		int L1 = left;
		int R1 = pr;
		int L2 = pl;
		int R2 = right;
		if (R1 - L1 > R2 - L2) {
			swap(int, R1, R2);
			swap(int, L1, L2);
		}
		if (L2 < R2) {
			Push(&stk, L2);
			Push(&stk, R2);
		}
		if (L1 < R1) {
			Push(&stk, L1);
			Push(&stk, R1);
		}
	}
	Terminate(&stk);
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
