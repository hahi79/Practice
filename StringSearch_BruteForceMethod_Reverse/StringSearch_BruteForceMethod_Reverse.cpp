//=========================================================
//	文字列探索　力まかせ方
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <string.h> // strlen()

// 関数プロトタイプ
int bf_matchr(const char* string, const char* pattern);

const int NOT_FOUND = -1;

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("力まかせ法");
		printf("テキスト:");
		scanf("%s", str1);

		printf("パターン:");
		scanf("%s", str2);

		int idx = bf_matchr(str1, str2);
		if (idx == NOT_FOUND) {
			puts("テキスト中にパターンは存在しません");
		}
		else {
			printf("%d文字目にマッチしました\n", idx + 1);
		}
		putchar('\n');
	}
	return 0;
}

int bf_matchr(const char* txt, const char* pat)
{
	int txtLen = strlen(txt);
	int patLen = strlen(pat);

	int cmpStart = txtLen - patLen;
	while (cmpStart >= 0) {
		int pt = cmpStart;
		int pp = 0;
		while (txt[pt] == pat[pp]) {
			if (pp == patLen - 1) {
				return cmpStart;
			}
			pp++;
			pt++;
		}
		cmpStart--;
	}
	return NOT_FOUND;
}
