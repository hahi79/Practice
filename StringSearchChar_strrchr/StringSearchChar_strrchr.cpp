﻿//=========================================================
//	文字列から文字検索 strrchr互換
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

const int NOT_FOUND = -1;

// 関数プロトタイプ
const char *str_rchr(const char* str,int ch);

int main()
{
	char str[256];
	char tmp[256];
	char ch;
	while (true) {
		printf("文字列:");
		scanf("%s", str);
		printf("検索文字:");
		scanf("%s", tmp);
		ch = tmp[0];

		const char*p = str_rchr(str, ch);
		if (p == nullptr) {
			printf("文字'%c'は文字列中に存在しません\n", ch);
		}
		else {
			printf("文字'%c'は%d文字目に存在します\n", ch, (p-str)+1);
		}
		putchar('\n');
	}
	return 0;
}

const char* str_rchr(const char* str, int c)
{
	const char* hit = nullptr;
	c = (char)c;
	while (true) {
		if (*str == c) {
			hit = str;
		}
		if (*str == '\0') {
			break;
		}
		str++;
	}
	return hit;
}
