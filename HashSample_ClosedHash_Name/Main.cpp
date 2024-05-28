﻿//==========================================================
//	クローズドハッシュ法によるハッシュの利用例
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "ClosedHash.h"
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;

// 関数プロトタイプ
Menu SelectMenu(void);
void setup(ClosedHash* h);

int main()
{
	const int HASH_SIZE = 13;
	Menu menu;
	ClosedHash hash;
	ClosedHashResult result = Initialize(&hash, HASH_SIZE);
	if (result != SUCCESS) {
		printf("初期化失敗!\n");
		exit(1);
	}
	setup(&hash);
	do {
		Member x;
		Bucket* temp;
		menu = SelectMenu();
		switch (menu) {
		case ADD:
			x = ScanMember("追加", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result != SUCCESS) {
				const char* cause = result == ADD_ALREADY_EXIST ? "登録済" : "テーブル不足";
				printf("追加に失敗しました(%s)\n", cause);
			}
			break;
		case DELETE:
			x = ScanMember("削除", MEMBER_NAME);
			result = Remove(&hash, &x);
			if (result != SUCCESS) {
				printf("\nエラー:その番号のデータは存在しません\n");
			}
			break;
		case SEARCH:
			x = ScanMember("探索", MEMBER_NAME);
			temp = Search(&hash, &x);
			if (temp == nullptr) {
				printf("\n探索に失敗しました\n");
			}
			else {
				printf("探索に成功しました:");
				PrintLnMember(&temp->data);
			}
			break;
		case CLEAR:
			Clear(&hash);
			break;
		case DUMP:
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&hash);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)追加 2)削除 3)探索 4)全削除 5)ダンプ 0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || DUMP < ch);
	return (Menu)ch;
}
void setup(ClosedHash* h)
{
	Member data[] = {
		{1,"赤尾"},
		{5,"武田"},
		{10,"小野"},
		{12,"鈴木"},
		{14,"神崎"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		Add(h, &data[i]);
	}
}
