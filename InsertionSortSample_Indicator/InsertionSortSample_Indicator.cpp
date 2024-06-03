//=========================================================
//	単純挿入ソート 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void InsertionSort(int array[], int arraySize);
void indicator(int idx, int array[], int arraySize);
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
		InsertionSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void InsertionSort(int array[], int arraySize)
{
	for (int i = 1; i < arraySize; i++) {
		indicator(i, array, arraySize);
		int tmp = array[i];
		int j;
		for (j = i; j > 0 && array[j - 1] > tmp; j--) {
			array[j] = array[j - 1];
		}
		array[j] = tmp;
	}
}

void indicator(int idx, int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("%4d", array[i]);
	}
	putchar('\n');
	int insert = idx;
	for (; insert > 0 && array[insert-1] > array[idx]; insert--) {
		/* nothing */
	}
	for (int i = 0; i < arraySize; i++) {
		const char* mark = "";
		if (i == insert) {
			mark = (i == idx) ? "^--+" : "^---";
		}
		else if (i == idx) {
			mark = "---+";
		}
		else if (insert<i && i < idx) {
			mark = "----";
		}
		printf("%4s", mark);
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
