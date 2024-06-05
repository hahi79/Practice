//=========================================================
//	ヒープソート
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void HeapSort(int array[], int arraySize);
void downheap(int array[], int left, int right);
void indicate(int array[], int arraySize);
void printSpace(int n);
int powerOf2(int n);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)  do{ type tmp=a; a=b; b=tmp;}while(false)

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
		HeapSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void HeapSort(int array[], int arraySize)
{
	puts("配列をヒープ化します。");
	for (int i = (arraySize - 1) / 2; i >= 0; i--) {
		indicate(array, arraySize);
		downheap(array, i, arraySize - 1);
	}
	puts("ヒープをもとにソートを行います。");
	for (int i = arraySize - 1; i > 0; i--) {
		swap(int, array[0], array[i]);
		indicate(array, arraySize);
		downheap(array, 0, i - 1);
	}
}

void downheap(int array[], int left, int right)
{
	int temp = array[left];  // 根
	int child;
	int parent=left;
	while (parent < (right + 1) / 2) {
		int cl = parent * 2 + 1;  // 左の子
		int cr = cl + 1;          // 右の子
		child = (cr <= right && array[cr] > array[cl]) ? cr : cl; // 大きい方の子
		if (temp >= array[child]) {
			break;
		}
		array[parent] = array[child];
		parent = child;
	}
	array[parent] = temp;
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

void indicate(int array[], int arraySize)
{
	puts("----------------------------------");
	int height = 1; // 木の高さ
	int i = arraySize;
	while ((i /= 2 )!= 0) {
		height++;
	}

	int idx = 0;
	int level_w = 1;
	for (int level = 0; level < height; level++) {
		printSpace(powerOf2(height - level) - 2);
		for(int j=0; j<level_w; j++){
			printf("%2d", array[idx++]);
			if (idx >= arraySize) goto exit;
			printSpace(powerOf2(height - level + 1) - 2);
		}
		putchar('\n');
		printSpace(powerOf2(height - level) - 3);
		for (int k = 0; k < level_w; k++) {
			if (2 * k + idx < arraySize)printf("／");
			if (2 * k + idx + 1 < arraySize)printf("＼");
			printSpace(powerOf2(height - level + 1) - 4);
		}
		putchar('\n');
		level_w *= 2;
	}
exit:
	putchar('\n');
}
void printSpace(int n) 
{
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}
int powerOf2(int n)
{
	int power = 1;
	while (n > 0) {
		power *= 2;
		n--;
	}
	return power;
}

