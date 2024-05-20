//==========================================================
//	配列サンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int MaxOfFour(int a, int b, int c, int d);

const int N = 5;

int main()
{
	srand(time(NULL));

	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < N; i++) {
		printf("a[%d] =%d\n", i, a[i]);
	}
	return 0;
}
