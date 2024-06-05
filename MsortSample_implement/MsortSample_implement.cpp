//=========================================================
//	msort 実装
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include <stdint.h>  // intptr_t
#include <memory.h>  // memcpy()
// 関数プロトタイプ
void m_sort(void* base, size_t nmenb, size_t size, int (*compar)(const void*, const void*));
void __m_sort(void *base, size_t nmenb,size_t size, int (*compar)(const void*, const void*));
void* getAdrs(void* base, size_t size, int idx);
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
		m_sort(
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

void* buff;

void m_sort(void* base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
{
	buff = (void*)calloc(nmemb, size);
	if (buff == nullptr) {
		exit(1);
	}
	__m_sort(base, nmemb, size, compare);
	free(buff);
}

void __m_sort(void* base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
{
	if (nmemb > 1) {
		int left = 0;
		int right = nmemb - 1;
		int center = (left + right) / 2;

		int leftSize = center - left + 1;
		__m_sort(base, leftSize, size, compare);
		int rightSize = right - (center + 1) + 1;
		__m_sort(getAdrs(base, size, center + 1), rightSize, size, compare);

		for (int i = left; i <= center; i++) {
			void* adrs1 = getAdrs(buff, size, i);
			void* adrs2 = getAdrs(base, size, i);
			memcpy(adrs1, adrs2, size);
		}

		int pa = left;
		int pb = center + 1;
		int pc = left;
		while (pa <= center && pb <= right) {
			void* adrsA = getAdrs(buff, size, pa);
			void* adrsB = getAdrs(base, size, pb);
			void* adrsC = getAdrs(base, size, pc);
			if (compare(adrsA, adrsB) <= 0) {
				memcpy(adrsC, adrsA, size);
				pa++;
			}
			else {
				memcpy(adrsC, adrsB, size);
				pb++;
			}
			pc++;
		}
		while (pa <= center) {
			void* adrsA = getAdrs(buff, size, pa);
			void* adrsC = getAdrs(base, size, pc);
			memcpy(adrsC, adrsA, size);
			pa++, pc++;
		}
		// 以下は必要ない
		//while (pb <= right) {
		//	void* adrsB = getAdrs(buff, size, pb);
		//	void* adrsC = getAdrs(base, size, pc);
		//	memcpy(adrsC, adrsB, size);
		//	pb++,pc++;
		//}
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
