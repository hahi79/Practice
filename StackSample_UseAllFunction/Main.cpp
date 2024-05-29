//=========================================================
//	スタックサンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntStack.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE,PUSH,POP,PEEK,PRINT,CLEAR,SEARCH
} Menu;

// 関数プロトタイプ
Menu SelectMenu();
void setup(IntStack *s);

int main()
{
	const int STACK_SIZE = 64;

	IntStack s;
	IntStackResult result = Initialize(&s, STACK_SIZE);
	if (result != SUCCESS) {
		printf("初期化失敗\n");
		exit(1);
	}
	setup(&s);
	Menu menu;
	do {
		int x;
		printf("現在のデータ数: % d / % d\n", Size(&s), Capacity(&s));
		menu = SelectMenu();
		switch (menu) {
		case PUSH:
			if (IsFull(&s)) {
				puts("スタックは満杯です");
				break;
			}
			printf("データ:");
			scanf("%d", &x);
			result = Push(&s, x);
			if (result != SUCCESS) {
				puts("エラー:プッシュに失敗しました");
			}
			break;
		case POP:
			if (IsEmpty(&s)) {
				puts("スタックは空です");
				break;
			}
			result = Pop(&s, &x);
			if (result != SUCCESS) {
				puts("エラー:ポップに失敗しました");
			}
			else {
				printf("ポップしたデータは%dです\n", x);
			}
			break;
		case PEEK:
			if (IsEmpty(&s)) {
				puts("スタックは空です");
				break;
			}
			result = Peek(&s, &x);
			if (result != SUCCESS) {
				puts("エラー:ピークに失敗しました");
			}
			else {
				printf("ピークしたデータは%dです\n", x);
			}
			break;
		case PRINT:
			Print(&s);
			break;
		case CLEAR:
			Clear(&s);
			puts("スタックを空にしました");
			break;
		case SEARCH:
			printf("検索データ:");
			scanf("%d", &x);
			int idx = Search(&s, x);
			if (idx == SEARCH_NOT_FOUND) {
				puts("データは発見できません");
			}
			else {
				printf("データは トップから%d番目 にあります\n", s.ptr-idx);
			}
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
		printf("1)プッシュ 2)ポップ 3)ピーク 4)表示 5)クリア 6)検索 0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || SEARCH < ch);
	return (Menu)ch;
}

void setup(IntStack* s)
{
	int data[] = { 1,2,3,4, };
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		Push(s, data[i]);
	}
}