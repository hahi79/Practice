//=========================================================
//	文字列の長さ strlen互換
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
size_t str_len(const char* str);
size_t str_len2(const char* str);
size_t str_len3(const char* str);

int main()
{
	char str[256];
	while (true) {
		printf("文字列:");
		scanf("%s", str);

		size_t len = str_len(str);
		size_t len2 = str_len2(str);
		size_t len3 = str_len3(str);
		printf("その文字列は%d文字です\n", len);
		printf("その文字列は%d文字です\n", len2);
		printf("その文字列は%d文字です\n", len3);
		putchar('\n');
	}
	return 0;
}

size_t str_len(const char* str)
{
	size_t len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
size_t str_len2(const char* str)
{
	size_t len = 0;
	while (*str++ != '\0') {
		len++;
	}
	return len;
}
size_t str_len3(const char* str)
{
	const char* p = str;
	int len = 0;
	while (*str != '\0') {
		str++;
	}
	return (size_t)(str - p);
}
