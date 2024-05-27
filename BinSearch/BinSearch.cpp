//==========================================================
//	線形探索 binsearch(バイナリーサーチ)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
void* binsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int (*compFunc)(const void*, const void*));
int CompareInt(const int* a, const int* b);
int getRandRange(int min, int max);

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
		const int DATA_RANGE = 30;
		int tmp = 0;
		for (int i = 0; i < dataSize; i++) {
			tmp += getRandRange(1, DATA_RANGE / dataSize);
			data[i] = tmp;
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(1, tmp);
		printf("探す値:%d\n", key);

		void* p = binsearch(
			&key,        // 検索キーのアドレス
			data,        // データ配列
			dataSize,    // データ配列の要素数
			sizeof(int), // 要素のサイズ
			(int (*)(const void*, const void*))CompareInt   // 比較関数
		);
		if (p == nullptr) {
			puts("探索に失敗しました");
		}
		else {
			int idx = (int*)p - data;
			printf("%d は data[%d] にあります\n", key, idx);
		}
		free(data);
	}
	return 0;
}

void* binsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int compFunc(const void*, const void*))
{
	int left = 0;
	int right = arraySize - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		void* midp = (void*)((intptr_t)array + typeSize * mid);
		int res = compFunc(key, midp);
		if (res == 0) {		// key == array[mid]
			return midp;
		}
		else if (res < 0) { // key < array[mid]
			right = mid - 1;
		}
		else {  // key > array[mid]
			left = mid + 1;
		}
	}
	return nullptr;
}

int CompareInt(const int* a, const int* b)
{
	return *a - *b;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
