//=========================================================
//	Intデックサンプルmain
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntDeque.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE,ENQUE_FRONT,ENQUE_REAR,DEQUE_FRONT,DEQUE_REAR,PEEK_FRONT,PEEK_REAR,PRINT,CLEAR,SEARCH
} Menu;

// 関数プロトタイプ
Menu SelectMenu();
void setup(IntDeque* que);

int main()
{
	const int QUEUE_SIZE = 8;

	IntDeque que;
	IntDequeResult result;
	result = Initialize(&que, QUEUE_SIZE);
	if (result != SUCCESS) {
		puts("キューの生成に失敗しました");
		exit(1);
	}
	setup(&que);
	Menu menu;
	do {
		int x;
		printf("現在のデータ数:%d / %d\n", Size(&que), Capacity(&que));
		menu = SelectMenu();
		switch (menu) {
		case ENQUE_FRONT:
		case ENQUE_REAR:
			if (IsFull(&que)) {
				puts("\aエラー:キューは満杯です");
				break;
			}
			printf("データ:");
			scanf("%d", &x);
			result = (menu == ENQUE_FRONT) ? EnqueFront(&que, x) : EnqueRear(&que, x);
			if (result != SUCCESS) {
				puts("\aエラー:エンキューに失敗しました");
			}
			break;
		case DEQUE_FRONT:
		case DEQUE_REAR:
			if (IsEmpty(&que)) {
				puts("\aエラー:キューは空です");
				break;
			}
			result = (menu==DEQUE_FRONT)?DequeFront(&que,&x): DequeRear(&que, &x);
			if (result != SUCCESS) {
				puts("\aエラー:デキューに失敗しました");
			}
			else {
				printf("デキューしたデータは %d です\n", x);
			}
			break;
		case PEEK_FRONT:
		case PEEK_REAR:
			if (IsEmpty(&que)) {
				puts("\aエラー:キューは空です");
				break;
			}
			result = (menu==PEEK_FRONT)?PeekFront(&que, &x): PeekRear(&que, &x);
			if (result != SUCCESS) {
				puts("\aエラー:ピークに失敗しました");
			}
			else {
				printf("ピークしたデータは %d です\n", x);
			}
			break;
		case PRINT:
			Print(&que);
			break;
		case CLEAR:
			Clear(&que);
			break;
		case SEARCH:
			printf("検索データ:");
			scanf("%d", &x);
			int idx = Search(&que, x);
			if (idx == SEARCH_NOT_FOUND) {
				puts("データは見つかりません");
			}
			else {
				printf("%d は データ先頭から%d番目にあります\n", x, idx + 1);
			}
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&que);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)エンキュー(FRONT) 3)デキュー(FRONT) 5)ピーク(FRONT)\n"
			   "2)エンキュー(REAR)  4)デキュー(REAR)  6)ピーク(REAR)\n"
			   "7)表示 8)クリア 9)検索 0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || SEARCH < ch);
	return (Menu)ch;
}

void setup(IntDeque* que)
{
	int data1[] = { 1,2,3 };
	int data2[] = { 4,5,6 };
	int dataSize1 = sizeof(data1) / sizeof(data1[0]);
	int dataSize2 = sizeof(data2) / sizeof(data2[0]);
	for (int i = 0; i < dataSize1; i++) {
		EnqueFront(que, data1[i]);
	}
	for (int i = 0; i < dataSize2; i++) {
		EnqueRear(que, data2[i]);
	}
}
