//==========================================================
//	線形探索　経過表示 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
int LinearSearch(int data[], int dataSize, int ley);
int getRandRange(int min, int max);
void Indicate(int data[], int dataSize, int idx);

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
            tmp += getRandRange(1, DATA_RANGE / dataSize);
            data[i] = tmp;
            printf("data[%d]:%d\n", i, data[i]);
        }
        int key = getRandRange(1, tmp);
        printf("探す値:%d\n", key);

        int idx = LinearSearch(data, dataSize, key);
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

int LinearSearch(int data[], int dataSize, int key)
{
    for (int i = 0; i < dataSize; i++) {
        Indicate(data, dataSize, i);
        if (data[i] == key) {
            return i;
        }
    }
    return SEARCH_FAIL;
}

void Indicate(int data[], int dataSize, int idx)
{
    const char* SP = "";
    const char* AS = "*";
    if (idx == 0) {
        printf("%3s|",SP);
        for (int i = 0; i < dataSize; i++) {
            printf("%3d", i);
        }
        printf("\n");
        printf("---+");
        for (int i = 0; i < dataSize; i++) {
            printf("---");
        }
        printf("\n");
    }
    printf("%3s|", SP);
    for (int i = 0; i < idx; i++) {
        printf("%3s", SP);
    }
    printf("%3s\n", AS);
    printf("%3d|", idx);
    for (int i = 0; i < dataSize; i++) {
        printf("%3d", data[i]);
    }
    printf("\n");
}
int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}

