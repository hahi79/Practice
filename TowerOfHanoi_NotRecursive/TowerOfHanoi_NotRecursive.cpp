//=========================================================
//	ハノイの塔　解法(非再帰化)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include "IntStack.h"

typedef enum {
	A = 1,
	B = 2,
	C = 3,
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
	return 0;
}

void move(int no, POS from, POS to)
{
	IntStack stk;
	Initialize(&stk, 100);

	while (true) {
		if (no > 1) {
			Push(&stk, no);
			Push(&stk, from);
			Push(&stk, to);
			no = no - 1;
			to = (POS)((A + B + C) - from - to);
			continue;
		}
		printf("円盤[%d]を %s軸から %s軸へ移動\n", no, PosName[from], PosName[to]);
		if (IsEmpty(&stk) == false) {
			Pop(&stk, (int*)&to);
			Pop(&stk, (int*)&from);
			Pop(&stk, &no);
			printf("円盤[%d]を %s軸から %s軸へ移動\n", no, PosName[from], PosName[to]);
			if (no > 1) {
				no = no - 1;
				from = (POS)((A + B + C) - from - to);
				continue;
			}
		}
		break;
	}

	Terminate(&stk);
}

