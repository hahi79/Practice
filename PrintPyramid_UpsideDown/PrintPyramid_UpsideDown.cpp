//==========================================================
//	ピラミッドを表示する 倒置
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// 関数プロトタイプ
void PrintPyramid_UpsideDown(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("何段のピラミッドですか? ");
			scanf("%d", &n);
		} while (n <= 0);
		PrintPyramid_UpsideDown(n);
	}
	return 0;
}

void PrintPyramid_UpsideDown(int n)
{
	for (int i = n; i >=1; i--) {
		char c = (n-i+1) % 10 + '0';
		int left = n - i;
		int center = (i - 1) * 2 + 1;
		for (int j = 0; j < left; j++) {
			printf(" ");
		}
		for (int j = 0; j < center; j++) {
			printf("%c",c);
		}
		printf("\n");
	}
}
