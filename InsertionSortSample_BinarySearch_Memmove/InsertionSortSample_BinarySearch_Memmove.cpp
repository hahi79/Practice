//=========================================================
//	単純挿入ソート２分探索 Memmove
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include <string.h>  // memmove()
// 関数プロトタイプ
void InsertionSort(int array[], int arraySize);
int SearchInsertIdx(int idx, int value, int array[]);
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
		int tmp = array[i];
		int insert = SearchInsertIdx(i, tmp, array);
		if (insert < i) {
			memmove(&array[insert + 1], &array[insert], sizeof(int) * (i - insert));
					
			array[insert] = tmp;
		}
	}
}
int SearchInsertIdx(int idx, int value, int array[])
{
	int left = 0;
	int right = idx - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (array[mid] <= value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
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