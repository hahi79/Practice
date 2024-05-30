//=========================================================
//	再帰アルゴリズムの解析
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()

// 関数プロトタイプ
void recur(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("数値:");
			scanf("%d", &n);
		} while (n < 0);

		recur(n);
	}
	return 0;
}

void recur(int n)
{
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}
