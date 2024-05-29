//=========================================================
//	スタックサンプル TWIN
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntStackTwin.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE,PUSH_A,PUSH_B,POP_A,POP_B,PEEK_A,PEEK_B,CLEAR_A,CLEAR_B,PRINT
} Menu;

// 関数プロトタイプ
Menu SelectMenu();
void setup(IntStackTwin *s);

int main()
{
	const int STACK_SIZE = 16;

	IntStackTwin s;
	IntStackResult result = Initialize(&s, STACK_SIZE);
	if (result != SUCCESS) {
		printf("初期化失敗\n");
		exit(1);
	}
	setup(&s);
	Menu menu;
	do {
		int x;
		printf("現在のデータ数: %d + %d / %d\n", SizeA(&s), SizeB(&s),Capacity(&s));
		menu = SelectMenu();
		switch (menu) {
		case PUSH_A:
		case PUSH_B:
			printf("データ:");
			scanf("%d", &x);
			result = (menu==PUSH_A)? PushA(&s, x): PushB(&s, x);
			if (result != SUCCESS) {
				puts("エラー:プッシュに失敗しました");
			}
			break;
		case POP_A:
		case POP_B:
			result = (menu==POP_A)? PopA(&s, &x): PopB(&s, &x);
			if (result != SUCCESS) {
				puts("エラー:ポップに失敗しました");
			}
			else {
				printf("ポップしたデータは%dです\n", x);
			}
			break;
		case PEEK_A:
		case PEEK_B:
			result = (menu==PEEK_A)?PeekA(&s, &x): PeekB(&s, &x);
			if (result != SUCCESS) {
				puts("エラー:ピークに失敗しました");
			}
			else {
				printf("ピークしたデータは%dです\n", x);
			}
			break;
		case CLEAR_A:
		case CLEAR_B:
			(menu == CLEAR_A) ? ClearA(&s) : ClearB(&s);
			break;
		case PRINT:
			Print(&s);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&s);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)プッシュA 3)ポップA 5)ピークA 7)クリアA\n"
			   "2)プッシュB 4)ポップB 6)ピークB 8)クリアB\n"
			   "9)表示 0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || PRINT < ch);
	return (Menu)ch;
}

void setup(IntStackTwin* s)
{
	int dataA[] = { 1,2,3,4, };
	int dataB[] = { 9,8,7,6, };
	int dataASize = sizeof(dataA) / sizeof(dataA[0]);
	int dataBSize = sizeof(dataB) / sizeof(dataB[0]);
	for (int i = 0; i < dataASize; i++) {
		PushA(s, dataA[i]);
	}
	for (int i = 0; i < dataBSize; i++) {
		PushB(s, dataB[i]);
	}
}