//=========================================================
//	qsort 実装
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include <stdint.h>  // intptr_t
// 関数プロトタイプ
void q_sort(void* base, size_t nmenb, size_t size, int (*compar)(const void*, const void*));
void* getAdrs(void* base, size_t size, int idx);
void swapMem(void* base, size_t size, int idx1, int idx2);
int CompareInt(const int* a, const int* b);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);
// 交換マクロ
#define swap(type,a,b)   do{ type tmp=a; a=b; b=tmp; }while(false)

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
		q_sort(
			array,            // 配列
			arraySize,        // 配列の要素数
			sizeof(array[0]), // 要素のサイズ
			(int(*)(const void *,const void*))CompareInt // 比較関数
		);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void q_sort(void* base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
{
	int left = 0;
	int right = nmemb - 1;
	int pl = left;
	int pr = right;
	int m = (left + right) / 2;
	void* x = getAdrs(base, size, m);

	do {
		while (compare(getAdrs(base, size, pl), x) < 0)pl++;
		while (compare(getAdrs(base, size, pr), x) > 0)pr--;
		if (pl <= pr) {
			swapMem(base, size, pl, pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) q_sort(getAdrs(base, size, left), pr - left+1, size, compare);
	if (pl < right) q_sort(getAdrs(base, size, pl), right - pl+1, size, compare);
}

void swapMem(void* base, size_t size, int idx1, int idx2)
{
	char temp;
	char* adr1 = (char*)getAdrs(base, size, idx1);
	char* adr2 = (char*)getAdrs(base, size, idx2);
	for (int i = 0; i < size; i++) {
		temp = *adr1;
		*adr1 = *adr2;
		*adr2 = temp;
		adr1++, adr2++;
	}
}

void* getAdrs(void* base, size_t size, int idx)
{
	intptr_t adrs=(intptr_t)base + idx * size;
	return (void*)adrs;
}

int CompareInt(const int* a, const int* b)
{
	return *a - *b;
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
