//=========================================================
//	再帰アルゴリズムの解析2
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()

// 関数プロトタイプ
void recur2(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("数値:");
			scanf("%d", &n);
		} while (n < 0);

		recur2(n);
	}
	return 0;
}

void recur2(int n)
{
	if (n > 0) {
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}