//=========================================================
//	文字列探索　str_str関数
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
// 関数プロトタイプ
const char *str_str(const char* txt, const char* pat);

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("str_str関数");
		printf("テキスト:");
		scanf("%s", str1);

		printf("パターン:");
		scanf("%s", str2);

		const char *p = str_str(str1, str2);
		if (p==nullptr) {
			puts("テキスト中にパターンは存在しません");
		}
		else {
			int idx = p - str1;
			printf("%d文字目にマッチしました\n", idx + 1);
			printf("%s\n", str1);
			printf("%*s|\n", idx, "");
			printf("%*s%s\n", idx, "", str2);
		}
		putchar('\n');
	}
	return 0;
}

const char *str_str(const char* txt, const char* pat)
{
	int cmpStart = 0;
	int pt = cmpStart;
	int pp = 0;
	int pStart = pt;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			cmpStart++;
			pt = cmpStart;
			pp = 0;
		}
	}
	if (pat[pp] == '\0') {
		return &txt[cmpStart];
	}
	return nullptr;
}
