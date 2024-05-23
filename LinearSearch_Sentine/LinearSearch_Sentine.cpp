//==========================================================
//	線形探索 (番兵法)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
int LinearSearch(int data[], int dataSize, int ley);
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

		int* data = (int*)calloc(dataSize+1, sizeof(int));
		if (data == nullptr) {
			printf("calloc()失敗");
			exit(1);
		}
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, 50);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, 50);
		printf("探す値:%d\n", key);

		int idx = LinearSearch(data, dataSize, key);
		if (idx == SEARCH_FAIL) {
			puts("探索に失敗しました");
		}
		else {
			printf("%dはdata[%d]にあります\n", key, idx);
		}
		free(data);
	}
	return 0;
}

int LinearSearch(int data[], int dataSize, int key)
{
	int i = 0;
	data[dataSize] = key;
	while (true) {
		if (data[i] == key) {
			break;
		}
		i++;
	}
	return (i == dataSize) ? SEARCH_FAIL : i;
}


int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}

