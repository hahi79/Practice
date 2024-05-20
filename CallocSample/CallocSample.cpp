//==========================================================
//	callocサンプル 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // callc(),free()

int main()
{
	int* x = (int *)calloc(1, sizeof(int));
	if (x == nullptr) {
		puts("記憶域の確保に失敗しました\n");
	}
	else {
		*x = 57;
		printf("*x=%d\n", *x);
		free(x);
	}
	return 0;
}
