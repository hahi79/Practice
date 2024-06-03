//=========================================================
//	単純交換ソート 第３版 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void BubbleSort(int array[], int arraySize);
void indicate(int pass, int j, bool isSwap, int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int compCount;
int swapCount;

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
		compCount = 0;
		swapCount = 0;
		BubbleSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);
		printf("比較は %d 回でした\n", compCount);
		printf("交換は %d 回でした\n", swapCount);

		free(array);
	}
	return 0;
}
 
void BubbleSort(int array[], int arraySize)
{
	int k = 0;
	int pass = 0;
	while(k < arraySize - 1) {
		pass++;
		int last = arraySize - 1;
		for (int j = arraySize - 1; j > k; j--) {
			bool isSwap = array[j - 1] > array[j];
			compCount++;
			indicate(pass, j, isSwap, array, arraySize);
			if (isSwap) {
				swap(int, array[j - 1], array[j]);
				last = j;
				swapCount++;
			}
		}
		k = last;
	}
}

void indicate(int pass, int j, bool isSwap, int array[], int arraySize)
{
	if (j == arraySize - 1) {
		printf("パス %d:\n", pass);
	}
	for (int k = 0; k < arraySize; k++) {
		int mark = ' ';
		if (k == j - 1) {
			mark = isSwap ? '+' : '-';
		}
		printf("%3d %c", array[k], mark);
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