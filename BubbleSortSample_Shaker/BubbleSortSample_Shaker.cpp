//=========================================================
//	単純交換ソート Shaker Sort
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void BubbleSort(int array[], int arraySize);
void indicate(int pass, int left, int right, int j, bool isSwap, int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
void SortTest(int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int compCount;
int swapCount;

int main()
{
	srand(time(NULL));
	char yesno;

	do {
		printf("サンプル(y/n)?");
		scanf("%c", &yesno);
	} while (yesno != 'y' && yesno != 'n');
	if (yesno == 'y') {
		int sample[] = { 9,1,3,4,6,7,8 };
		int sampleSize = sizeof(sample) / sizeof(sample[0]);
		SortTest(sample, sampleSize);
	}
	else {
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
			SortTest(array, arraySize);
			free(array);
		}
	}
	return 0;
}
void SortTest(int array[], int arraySize)
{
	dumpArray(array, arraySize);
	compCount = 0;
	swapCount = 0;
	BubbleSort(array, arraySize);
	printf("昇順にソートしました\n");
	dumpArray(array, arraySize);
	printf("比較は %d 回でした\n", compCount);
	printf("交換は %d 回でした\n", swapCount);
}


void BubbleSort(int array[], int arraySize)
{
	int left = 0;
	int right = arraySize - 1;
	int pass = 0;
	while (left < right ) {
		pass++;
		int dispPass = pass;
		if (pass%2!=0) {
			int last = right;
			for (int j = right; j > left; j--) {
				bool isSwap = array[j - 1] > array[j];
				compCount++;
				indicate(dispPass, left, right, j, isSwap, array, arraySize);
				dispPass = -1;
				if (isSwap) {
					swap(int, array[j - 1], array[j]);
					swapCount++;
					last = j;
				}
			}
			left = last;
		}
		else {
			int last = left;
			for (int j = left; j < right; j++) {
				bool isSwap = array[j] > array[j + 1];
				indicate(dispPass, left, right, j + 1, isSwap, array, arraySize);
				dispPass = -1;
				if (isSwap) {
					swap(int, array[j], array[j + 1]);
					swapCount++;
					last = j;
				}
			}
			right = last;
		}
	}
}

void indicate(int pass, int left, int right, int j, bool isSwap, int array[], int arraySize)
{
	if (pass>=1) {
		printf("パス %d:\n", pass);
		for (int i = 0; i <= arraySize; i++) {
			const char* mark=(i == left) ? "L" : ((i == right) ? "R" : "");
			printf("%3s  ", mark);
		}
		putchar('\n');
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