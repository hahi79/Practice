//=========================================================
//	単純挿入ソート 番兵
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void InsertionSort_Sentinel(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

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

		array = (int*)calloc(arraySize+1, sizeof(int));
		if (array == nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i+1] = getRandRange(1, 100);
		}
		dumpArray(&array[1], arraySize);
		InsertionSort_Sentinel(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(&array[1], arraySize);

		free(array);
	}
	return 0;
}

void InsertionSort_Sentinel(int array[], int arraySize)
{
	for (int i = 2; i < arraySize+1; i++) {
		int tmp = array[i];
		array[0] = tmp - 1;
		int j;
		for (j = i; array[j - 1] > tmp; j--) {
			array[j] = array[j - 1];
		}
		array[j] = tmp;
	}
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