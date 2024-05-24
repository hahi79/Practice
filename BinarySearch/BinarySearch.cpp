﻿//==========================================================
//	２分探索 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
int BinarySearch(int data[], int dataSize, int ley);
int getRandRange(int min, int max);

#define SEARCH_FAIL (-1)

int main()
{
	srand(time(NULL));
	int dataSize;

	while (true) {
		printf("要素数:");
		do {
			scanf("%d", &dataSize);
		} while (dataSize <= 0);

		int* data = (int*)calloc(dataSize, sizeof(int));
		if (data == nullptr) {
			printf("calloc()失敗");
			exit(1);
		}
		const int DATA_RANGE = 100;
		int tmp = 0;
		for (int i = 0; i < dataSize; i++) {
			tmp+= getRandRange(1, DATA_RANGE/dataSize);
			data[i] = tmp;
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(1, tmp);
		printf("探す値:%d\n", key);

		int idx = BinarySearch(data, dataSize, key);
		if (idx == SEARCH_FAIL) {
			puts("探索に失敗しました");
		}
		else {
			printf("%d は data[%d] にあります\n", key, idx);
		}
		free(data);
	}
	return 0;
}

int BinarySearch(int data[], int dataSize, int key)
{
	int left = 0;
	int right = dataSize - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (key == data[mid]) {
			return mid;
		}
		else if (key < data[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return SEARCH_FAIL;

		;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
