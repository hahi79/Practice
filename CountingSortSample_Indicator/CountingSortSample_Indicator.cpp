//=========================================================
//	度数ソート 経過表示
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void CountingSort(int array[], int arraySize, int valueMax);
void indicateArray(int array[], int arraySize, const char* title);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

int main()
{
	srand(time(NULL));
	int arraySize;
	int* array;
	const int VALUE_MAX = 20;

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
			array[i] = getRandRange(1, VALUE_MAX);
		}
		//dumpArray(array, arraySize);
		CountingSort(array, arraySize,VALUE_MAX);
		//printf("昇順にソートしました\n");
		//dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void CountingSort(int array[], int arraySize, int valueMax)
{
	int* count = (int*)calloc(valueMax + 1, sizeof(int)); // 累積度数の配列
	int* sort = (int*)calloc(arraySize, sizeof(int));   // ソート作業の配列
	if (count == nullptr || sort == nullptr) {
		puts("calloc失敗");
		exit(1);
	}

	indicateArray(array, arraySize, "ソート前配列");

	// step0 : 
	for (int i = 0; i <= valueMax; i++) {
		count[i] = 0;
	}
	// step1
	for (int i = 0; i < arraySize; i++) {
		int value = array[i];
		if (value < 0 || valueMax < value) {
			puts("0～max以外のデータがありました\n");
			exit(1);
		}
		count[value]++;
	}
	indicateArray(count, valueMax + 1, "度数分布");

	// step2
	for (int i = 1; i <= valueMax; i++) {
		count[i] += count[i - 1];
	}
	indicateArray(count, valueMax + 1, "累積度数分布");
	// step3
	for (int i = arraySize - 1; i >= 0; i--) {
		int value = array[i];
		int idx = --count[value];
		sort[idx] = value;
		printf("array[%d]の%2dをsort[%d]に格納\n", i, value, idx);
	}
	putchar('\n');
	// step4
	for (int i = 0; i < arraySize; i++) {
		array[i] = sort[i];
	}
	indicateArray(array, arraySize, "ソート後配列");
	free(sort);
	free(count);
}

void indicateArray(int array[], int arraySize,const char* title)
{
	puts(title);
	for (int i = 0; i < arraySize; i++) {
		printf("%3d", i);
	}
	putchar('\n');
	for (int i = 0; i < arraySize; i++) {
		printf("---");
	}
	putchar('\n');
	for (int i = 0; i < arraySize; i++) {
		printf("%3d", array[i]);
	}
	putchar('\n');
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
