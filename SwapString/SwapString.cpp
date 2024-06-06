//=========================================================
//	文字列の交換
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf scanf()
// 関数プロトタイプ
void swap_str(char* x, char* y);


int main()
{
	const int STRING_SIZE = 128;
	char s1[STRING_SIZE];
	char s2[STRING_SIZE];

	while (true) {
		printf("文字列s1:");
		scanf("%s", s1);
		printf("文字列s2:");
		scanf("%s", s2);

		swap_str(s1, s2);
		puts("\n文字列s1とs2の内容を交換しました");

		printf("文字列s1は\"%s\"です\n", s1);
		printf("文字列s2は\"%s\"です\n", s2);
		putchar('\n');
	}
	return 0;
}

void swap_str(char* x, char* y)
{
	bool xEnd = false;
	bool yEnd = false;
	char c1, c2;
	while (xEnd == false && yEnd == false) {
		c1 = *x;
		c2 = *y;
		*x++ = c2;
		*y++ = c1;
		if (c1 == '\0') {
			xEnd = true;
		}
		if (c2 == '\0') {
			yEnd = true;
		}
	}
	while (xEnd == false) {
		c1 = (*y++ = *x++);
		if (c1 == '\0') {
			xEnd = true;
		}
	}
	while (yEnd == false) {
		c2 = (*x++ = *y++);
		if (c2 == '\0') {
			yEnd = true;
		}
	}
}
