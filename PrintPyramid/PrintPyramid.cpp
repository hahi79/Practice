//==========================================================
//	ピラミッドを表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// 関数プロトタイプ
void PrintPyramid(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("何段のピラミッドですか? ");
			scanf("%d", &n);
		} while (n <= 0);
		PrintPyramid(n);
	}
	return 0;
}

void PrintPyramid(int n)
{
	for (int i = 1; i <= n; i++) {
		int left = n - i;
		int center = (i - 1) * 2 + 1;
		for (int j = 0; j < left; j++) {
			printf(" ");
		}
		for (int j = 0; j < center; j++) {
			printf("*");
		}
		printf("\n");
	}
}
