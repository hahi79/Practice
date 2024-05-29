//=========================================================
//	Intキューサンプルmain
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntQueue.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE,ENQUE,DEQUE,PEEK,PRINT,CLEAR,SEARCH,SEARCH2
} Menu;

// 関数プロトタイプ
Menu SelectMenu();
void setup(IntQueue* que);

int main()
{
	const int QUEUE_SIZE = 8;

	IntQueue que;
	IntQueueResult result;
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
		case ENQUE:
			if (IsFull(&que)) {
				puts("\aエラー:キューが一杯です");
				break;
			}
			printf("データ:");
			scanf("%d", &x);
			result = Enque(&que, x);
			if (result != SUCCESS) {
				puts("\aエラー:エンキューに失敗しました");
			}
			break;
		case DEQUE:
			if (IsEmpty(&que)) {
				puts("\aエラー:データがありません");
				break;
			}
			result = Deque(&que,&x);
			if (result != SUCCESS) {
				puts("\aエラー:デキューに失敗しました");
			}
			else {
				printf("デキューしたデータは %d です\n", x);
			}
			break;
		case PEEK:
			if (IsEmpty(&que)) {
				puts("\aエラー:データがありません");
				break;
			}
			result = Peek(&que, &x);
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
		case SEARCH2:
			printf("検索データ:");
			scanf("%d", &x);
			int idx = (menu == SEARCH) ? Search(&que, x) : Search2(&que, x);
			if (idx == SEARCH_NOT_FOUND) {
				puts("データは見つかりません");
			}
			else {
				const char* where = (menu == SEARCH) ? "キュー配列の" : "データ先頭から";
				printf("データ%d は、%s %d番目にあります\n", x, where, idx + 1);
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
		printf("1)エンキュー 2)デキュー 3)ピーク 4)表示 5)クリア 6)検索 7)検索2 0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || SEARCH2 < ch);
	return (Menu)ch;
}

void setup(IntQueue* que)
{
	int data[] = { 1,2,3,4,5 };
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		Enque(que, data[i]);
	}
}
