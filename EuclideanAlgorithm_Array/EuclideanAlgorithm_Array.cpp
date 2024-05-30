//=========================================================
//	ユークリッドの互除法(配列)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // calloc(),free(),srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int gcd(int x, int y); // Greatest Common Divisor を求める
int gcd_array(const int array[], int arraySize);
int getRandRange(int min, int max);

int main()
{
	srand(time(NULL));

	int arraySize;
	int* array;
	while (true) {
		int arraySize;
		do {
			printf("配列の要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 1);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(2, 15)*getRandRange(2,15)* getRandRange(2, 15);
		}

		int ans = gcd_array(array,arraySize);
		for (int i = 0; i < arraySize; i++) {
			printf("%d ", array[i]);
		}
		printf("の最大公約数は %d\n", ans);

		free(array);
	}
	return 0;
}

int gcd_array(const int array[], int arraySize)
{
	int gcd_val = array[0];
	for (int i = 1; i < arraySize; i++) {
		gcd_val = gcd(gcd_val, array[i]);
	}
	return gcd_val;
}

int gcd(int x, int y)
{
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}