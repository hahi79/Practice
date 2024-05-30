//=========================================================
//	ハノイの塔　解法
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()

typedef enum {
	A=1,
	B=2,
	C=3,
} POS;

const char* PosName[] = { "","A","B","C" };

// 関数プロトタイプ
void move(int no, POS from, POS to);

int main()
{
	while (true) {
		int n;
		do {
			printf("ハノイの塔\a円盤の数:");
			scanf("%d", &n);
		} while (n < 1);

		move(n, A, C);
	}
}

void move(int no, POS from, POS to)
{
	POS tmp =(POS)((A + B + C) - from - to);
	if (no > 1) {
		move(no - 1, from, tmp);
	}
	printf("円盤[%d]を %s軸から %s軸へ移動\n", no, PosName[from], PosName[to]);
	if (no > 1) {
		move(no - 1, tmp, to);
	}
}
