﻿//==========================================================
//	アレイ線形リストサンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "ArrayLinkedList.h"
#include <stdio.h> // printf(),scanf()
	
typedef enum {
	TERMINATE,
	INSERT_FRONT,
	INSERT_REAR,
	REMOVE_FRONT,
	REMOVE_REAR,
	PRINT_CURRENT,
	REMOVE_CURRENT,
	SEARCH_NO,
	SEARCH_NAME,
	PRINT_ALL,
	CLEAR,
	PURGE_NO,
	PURGE_NAME,
	RETRIEVE,
} Menu;
	
// 関数プロトタイプ
Menu SelectMenu();
void setup(List *list);
	
int main()
{
	Menu menu;
	List list;
	
	Initialize(&list,30);
	setup(&list);
	do {
		Member x;
		Index idx;
		int no;
		menu = SelectMenu();
		switch (menu) {
		case INSERT_FRONT:
			x = ScanMember("先頭に挿入する", MEMBER_NO + MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		case INSERT_REAR:
			x = ScanMember("末尾に挿入する", MEMBER_NO + MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		case REMOVE_FRONT:
			RemoveFront(&list);
			break;
		case REMOVE_REAR:
			RemoveRear(&list);
			break;
		case PRINT_CURRENT:
			PrintLnCurrent(&list);
			break;
		case REMOVE_CURRENT:
			RemoveCurrent(&list);
			break;
		case SEARCH_NO:
			x=ScanMember("検索", MEMBER_NO);
			idx=Search(&list, &x, MemberNoCmp);
			if (idx != NullIndex) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("その番号のデータはありません");
			}
			break;
		case SEARCH_NAME:
			x = ScanMember("検索", MEMBER_NAME);
			idx = Search(&list, &x, MemberNameCmp);
			if (idx != NullIndex) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("その名前のデータはありません");
			}
			break;
		case PRINT_ALL:
			Print(&list);
			break;
		case CLEAR:
			Clear(&list);
			break;
		case PURGE_NO:
			Purge(&list, MemberNoCmp);
			puts("同じ番号の重複メンバーを削除しました");
			break;
		case PURGE_NAME:
			Purge(&list, MemberNameCmp);
			puts("同じ名前の重複メンバーを削除しました");
			break;
		case RETRIEVE:
			printf("先頭から何個後ろ:");
			scanf("%d", &no);
			idx = Retrieve(&list, no);
			if (idx != NullIndex) {
				printf("先頭から%d個後ろのデータは\n", no);
				PrintLnMember(&list.array[idx].data);
			}
			else {
				printf("先頭から%d個後ろのデータはありません", no);
			}
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);
	
	Terminate(&list);
	return 0;
}
		
Menu SelectMenu()
{
	int ch;
	const char* menuStr[] = {
		"先頭にノードを挿入",
		"末尾にノードを挿入",
		"先頭のノードを削除",
		"末尾のノードを削除",
		"着目ノードを表示",
		"着目ノードを削除",
		"番号で検索",
		"氏名で検索",
		"全ノードを表示",
		"全ノードを削除",
		"同一番号の重複削除",
		"同一氏名の重複削除",
		"N番目のデータ表示",
	};
	int menuStrSize = sizeof(menuStr) / sizeof(menuStr[0]);
	
	do {
		for (int i = 0; i < menuStrSize; i++) {
			printf("(%2d)%-18.18s  ", i + 1, menuStr[i]);
			if (i % 3 == 2) {
				putchar('\n');
			}
		}
		printf("( 0)終了\t:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || RETRIEVE < ch);
	return (Menu)ch;
}
void setup(List* list)
{
	Member data[] = {
		{1,"赤尾"},
		{5,"武田"},
		{10,"小野"},
		{12,"鈴木"},
		{14,"神崎"},
		{1,"ニセもの"},
		{100,"小野"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		InsertRear(list, &data[i]);
	}
}
