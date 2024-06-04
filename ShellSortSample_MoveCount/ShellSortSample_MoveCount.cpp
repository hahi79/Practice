//=========================================================
//	シェルソート 移動カウント
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include <string.h>  // memcpy()
// 関数プロトタイプ
void ShellSort(int array[], int arraySize);
void ShellSort_Rev2(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

int moveCount1;
int moveCount2;

int main()
{
	srand(time(NULL));
	int arraySize;
	int* array;
	int* arrayBuf;

	while (true) {
		do {
			printf("要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		arrayBuf= (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr || arrayBuf==nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 1000);
		}
		memcpy(arrayBuf, array, sizeof(int) * arraySize);
		dumpArray(arrayBuf, arraySize);
		moveCount1 = 0;
		moveCount2 = 0;
		ShellSort(arrayBuf, arraySize);
		memcpy(arrayBuf, array, sizeof(int) * arraySize);
		ShellSort_Rev2(arrayBuf, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(arrayBuf, arraySize);
		printf("移動回数1は%d回\n", moveCount1);
		printf("移動回数2は%d回\n", moveCount2);

		free(array);
		free(arrayBuf);
	}
	return 0;
}

void ShellSort(int array[], int arraySize)
{
	for (int h = arraySize / 2; h > 0; h /= 2) {
		for (int i = h; i < arraySize; i++) {
			int tmp = array[i];
			int j;
			for (j = i - h; j >= 0 && array[j] > tmp; j -= h) {
				array[j + h] = array[j];
				moveCount1++;
			}
			array[j + h] = tmp;
		}
	}
}

void ShellSort_Rev2(int array[], int arraySize)
{
	int h;
	for (h = 1; h < arraySize; h = h * 3 + 1) {
		/* nothing */
	}

	for (; h > 0; h /= 3) {
		for (int i = h; i < arraySize; i++) {
			int tmp = array[i];
			int j;
			for (j = i - h; j >= 0 && array[j] > tmp; j -= h) {
				array[j + h] = array[j];
				moveCount2++;
			}
			array[j + h] = tmp;
		}
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

